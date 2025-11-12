#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
const int N=1e5+5;
using namespace std;
using namespace __gnu_pbds;
int n,ans,dp[205][105][105];
struct node{
	int x,y,z,id;
}a[N];
bool cmp(node x,node y){
	return x.x>y.x;
}
bool cmp2(node x,node y){
	return abs(x.x-x.y)>abs(y.x-y.y);
}
void dfs(int d,int sum,int x,int y){
	if(x>n/2||y>n/2)
		return;
	if(d==n){
		if(x>n/2||y>n/2||(n-x-y)>n/2)
			return;
		if(ans<sum){
			ans=sum;
		}
		return;
	}
	dfs(d+1,sum+a[d+1].x,x+1,y);
	dfs(d+1,sum+a[d+1].y,x,y+1);
	dfs(d+1,sum+a[d+1].z,x,y);
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		bool f1=1,f2=1;
		ans=0;
		cin>>n;
		For(i,1,n){
			cin>>a[i].x>>a[i].y>>a[i].z,a[i].id=i;
			if(a[i].y||a[i].z)
				f1=0;
			if(a[i].z)
				f2=0;
		}
//		if(n<=200){
//			memset(dp,0,sizeof dp);
//			For(i,1,n){
//				For(j,0,n/2){
//					For(k,0,n/2){
//						if(j>0)
//							dp[i][j][k]=max(dp[i-1][j-1][k]+a[i].x,dp[i][j][k]);
//						if(k>0)
//							dp[i][j][k]=max(dp[i-1][j][k-1]+a[i].y,dp[i][j][k]);
//						dp[i][j][k]=max(dp[i-1][j][k]+a[i].z,dp[i][j][k]);
//					}
//				}
//			}
//			For(i,0,n/2){
//				For(j,0,n/2){
//					if(n-i-j<=n/2)
//						ans=max(ans,dp[n][i][j]);
//				}
//			}
//			cout<<ans<<'\n';
//			continue;
//		}
		if(f1){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			cout<<ans<<'\n';
			continue;
		}
		if(f2){
			int k1=0,k2=0,sum=0;
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y){
					if(k1<n/2)
						k1++,sum+=a[i].x;
					else
						k2++,sum+=a[i].y; 
				}
				else{
					if(k2<n/2)
						k2++,sum+=a[i].y;
					else
						k1++,sum+=a[i].x; 
				}
			}
			cout<<sum<<'\n';
			continue;
		}
		dfs(0,0,0,0);
		cout<<ans<<'\n';	
	}
	return 0;
}
