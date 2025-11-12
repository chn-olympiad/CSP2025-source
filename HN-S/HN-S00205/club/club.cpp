#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+20;
int T;
int a[N][5];
LL ans;

void dfs(int n,LL x,LL sum,LL a1,LL a2,LL a3){
	if(x==n){
		ans=max(sum,ans);
		return;
	}
	if(a1<n/2){
		dfs(n,x+1,sum+a[x+1][1],a1+1,a2,a3);
	}
	if(a2<n/2){
		dfs(n,x+1,sum+a[x+1][2],a1,a2+1,a3);
	}
	if(a3<n/2){
		dfs(n,x+1,sum+a[x+1][3],a1,a2,a3+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(n,0,0,0,0,0);
		cout<<ans<<endl;
	}
	
	return 0;
}
