#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+100;

struct peo{
	int a,b,c;
}myd[N];

bool cmp(peo x,peo y){
	return x.a-x.b>y.a-y.b;
}

int dp[2][N/2];//使用的次数 

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof dp);
		
		int n;
		cin >> n;
		int maxx1=0,maxx2=0;
		for (int i=1;i<=n;i++){
			cin >> myd[i].a >> myd[i].b >> myd[i].c;
			maxx1=max(maxx1,myd[i].b);
			maxx2=max(maxx2,myd[i].c);
		}
		sort(myd+1,myd+1+n,cmp);
//		for (int i=1;i<=n;i++){
//			cout <<  myd[i].a << " " << myd[i].b << " "<< myd[i].c << "\n";
//		}

//		for (int i=1;i<=n;i++){
//			for(int j=n/2;j>=0;j--){
//				dp[i&1][j]=dp[!(i&1)][j]+(i<=n/2?myd[i].a:myd[i].b);
//				if (j!=0)dp[i&1][j]=max(dp[i&1][j],dp[!(i&1)][j-1]+myd[i].c);
//				cout << dp[i&1][j] << " ";
//			}
//			cout << "\n";
//		}
//		
//		
//		int maxx=0;
//		for (int i=0;i<=n/2;i++){
//			maxx=max(dp[n&1][i],maxx);
//		}
//		cout << maxx << "\n";
		int sum=0;
		if (maxx2==0){
			for (int i=1;i<=n;i++){
				sum+=(i<=n/2?myd[i].a:myd[i].b);
			}
		}
		cout << sum << "\n";
	}

	
	return 0;
}
