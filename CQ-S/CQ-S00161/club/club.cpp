#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
int a[100005],b[100005],c[100005];
void dfs(int x,int ansa,int ansb,int ansc,int cnta,int cntb,int cntc){
	if(x==n){
		ans=max(ans,ansa+ansb+ansc);
		return ;
	}
	if(cnta==n/2){
		for(int i=x+1;i<=n;i++){
			dfs(i,ansa,ansb+b[i],ansc,cnta,cntb+1,cntc);
			dfs(i,ansa,ansb,ansc+c[i],cnta,cntb,cntc+1);
		}
	}
	else if(cntb==n/2){
		for(int i=x+1;i<=n;i++){
			dfs(i,ansa+a[i],ansb,ansc,cnta+1,cntb,cntc);
			dfs(i,ansa,ansb,ansc+c[i],cnta,cntb,cntc+1);
		}
	}
	else if(cntc==n/2){
		for(int i=x+1;i<=n;i++){
			dfs(i,ansa+a[i],ansb,ansc,cnta+1,cntb,cntc);
			dfs(i,ansa,ansb+b[i],ansc,cnta,cntb+1,cntc);
		}
	}
	else{
		for(int i=x+1;i<=n;i++){
			dfs(i,ansa+a[i],ansb,ansc,cnta+1,cntb,cntc);
			dfs(i,ansa,ansb+b[i],ansc,cnta,cntb+1,cntc);
			dfs(i,ansa,ansb,ansc+c[i],cnta,cntb,cntc+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=0,flag1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0){
				flag=1;
			}
			if(c[i]!=0){
				flag1=1;
			}
		} 
		if(flag==0&&flag1==0){
			sort(a+1,a+1+n);
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
		else{
			dfs(0,0,0,0,0,0,0);
			cout<<ans<<endl;
		}
		ans=0;
	}
	return 0;
}
