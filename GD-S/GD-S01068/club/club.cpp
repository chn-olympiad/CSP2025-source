#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct node{
	ll v,id;
}con[N];
ll labs(ll a){
	if(a>0) return a;
	return -a;
}
bool cmp(node a,node b){
	return a.v>b.v;
}
ll T,n,a[N][5],ans;
void dfs(int cnt1,int cnt2,int cnt3,int s,ll sum){
	if(s==n+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			if(cnt1==n/2) continue;
			dfs(cnt1+1,cnt2,cnt3,s+1,sum+a[s][1]);
		}else if(i==2){
			if(cnt2==n/2) continue;
			dfs(cnt1,cnt2+1,cnt3,s+1,sum+a[s][2]);			
		}else{
			if(cnt3==n/2) continue;
			dfs(cnt1,cnt2,cnt3+1,s+1,sum+a[s][3]);
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int f=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3],con[i].v=labs(a[i][1]-a[i][2]),con[i].id=i;
			if(a[i][3]!=0) f=1;
		}
		if(f==1){
			 dfs(0,0,0,1,0);
		}else{
			int cnt1=0,cnt2=0;
			sort(con+1,con+1+n,cmp);
			for(int i=1;i<=n;i++){
				int j=con[i].id,l=a[j][1],r=a[j][2];
				if(cnt1+1>n/2||cnt2+1>n/2){
					if(cnt1+1>n/2) ans+=r; 
					if(cnt2+1>n/2) ans+=l;
				}else{
					if(l>r) ans+=l,cnt1++;
					else ans+=r,cnt2++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
