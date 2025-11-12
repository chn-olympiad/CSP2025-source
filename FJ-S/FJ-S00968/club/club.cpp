#include<bits/stdc++.h>
using namespace std;

int T;
int n;
int maxx;

struct xue{
	int x,y,z,cha;
}a[100010];

int b[100010];

bool cmp(xue p,xue q){
	return p.x>q.x;
}

bool cmp1(xue p,xue q){
	return p.cha>q.cha;
}

int xyz(int p,int n){
	if(n==1) return a[p].x;
	else if(n==2) return a[p].y;
	else return a[p].z;
}
void dfs(int p,int ans,int cnt1,int cnt2,int cnt3){
	if(p>n){
//		cout<<"***   "<<ans<<"   ";
//		for(int i=1;i<=n;i++) cout<<b[i]<<' ';
//		cout<<"\n";
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1 && cnt1>=n/2) continue; 
		if(i==2 && cnt2>=n/2) continue;
		if(i==3 && cnt3>=n/2) continue;
		int k1=cnt1,k2=cnt2,k3=cnt3;
		if(i==1) k1++;
		else if(i==2) k2++;
		else if(i==3) k3++;
		b[p]=i;
		dfs(p+1,ans+xyz(p,i),k1,k2,k3);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z!=0 ) flag1=1,flag2=1;
			if(a[i].y!=0 ) flag1=1;
		}
		if(!flag1){
			int ans=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			} 
			cout<<ans<<"\n";
		} 
		else if(!flag2){
			int ans=0;
			for(int i=1;i<=n;i++){
				a[i].cha=abs(a[i].x-a[i].y);
			} 
			sort(a+1,a+1+n,cmp1);
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if(cnt1>n/2) ans+=a[i].y;
				else if(cnt2>n/2) ans+=a[i].x;
				else{
					if(a[i].x>=a[i].y){
						cnt1++;
						ans+=a[i].x; 
					}else{
						cnt2++;
						ans+=a[i].y;
					}	
				} 
			
			}
			cout<<ans<<"\n";
		}
		else{
			dfs(1,0,0,0,0);
			cout<<maxx<<"\n";
			maxx=0;
		}
		
	}
	return 0;
} 
