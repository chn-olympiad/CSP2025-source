#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=305;
int t,n,a[100005][4],dp[N][N][N];
int op[100005];
bool f;
void make(){
	int ans=0;
	sort(op+1,op+1+n);
	for(int i=n;i>n/2;--i){
		ans+=op[i];
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;++i){
		f=false;
		int ans=0;
		cin>>n;
		for(int j=1;j<=n;++j){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][3]||a[j][2]){
				f=true;
			}
		}
		if(!f){
			for(int j=1;j<=n;++j){
				op[j]=a[j][1];
			}
			make();
			continue;
		}
		for(int j=1;j<=n;++j){
			for(int k=0;k<=j;++k){
				for(int l=0;k+l<=j;++l){
					int o=j-k-l;
					if(k){
						dp[k][l][o]=max(dp[k][l][o],dp[k-1][l][o]+a[j][1]);
					}
					if(l){
						dp[k][l][o]=max(dp[k][l][o],dp[k][l-1][o]+a[j][2]);
					}
					if(o){
						dp[k][l][o]=max(dp[k][l][o],dp[k][l][o-1]+a[j][3]);
					}
				}
			}
		}
		for(int j=0;j<=n/2;++j){
			for(int k=n/2;k>=0;--k){
				int o=n-j-k;
				if(o>n/2){
					continue;
				}
				ans=max(ans,dp[j][k][o]);
//				printf("j=%d,k=%d,o=%d,dp[j][k][o]=%d\n",j,k,o,dp[j][k][o]);
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
		memset(dp,0,sizeof(dp));
	} 
	return 0;
}
