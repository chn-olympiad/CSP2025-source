#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
const int MAXN=1e5+5;
int i[MAXN][3];
ll ans=0;
void dfs(int now,ll cnt,int a,int b,int c){
	if(now==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(a<n/2){
		dfs(now+1,cnt+i[now][1],a+1,b,c);
	}
	if(b<n/2){
		dfs(now+1,cnt+i[now][2],a,b+1,c);
	}
	if(c<n/2){
		dfs(now+1,cnt+i[now][3],a,b,c+1);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>i[j][k];
			}
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
} 
