#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
const int N=1e4;
int n,a[N],ans=0,dp[5100][5100],dpz[5100][5100];
int cmp(int a,int b){
	return a>b;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		dp[n][1]=a[n];
		for(int j=n;j>i;j--){
			for(int j1=j+1;j1<=n;j1++){
				for(int ij=1;ij<=n-j1+1;ij++){
					dp[j][ij+1]=dp[j1][ij]+a[j];
					dpz[j][ij+1]=dpz[j1][ij]+1;
					if(dp[j][ij+1]>a[i]*2 and ij+1>=3){
						dpz[j][ij]++;
					}
				}
			}
			for(int j=i+1;i<=n;i++){
				for(int j1=1;j1<=n-j+1;j1++){
					ans+=dpz[j][j1];
				}
			}
		}
	}
	cout<<ans;
    return 0;
}