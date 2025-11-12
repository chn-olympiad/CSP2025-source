#include<bits/stdc++.h>
//#define INF 2e18
#define fi first
#define se second
#define endl '\n'
//#define int long long
#define mem(x,v) memset(x,v,sizeof x)
using namespace std;
const int N = 1e5+5;
const int NA = 205;

int T,n;
int a[N][5];
int f[NA][NA][NA];

void solve(){
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	if(n<=200){
		mem(f,0);int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++)for(int k=0;k<=i-j;k++){
				int l=i-j-k;if(l<0)continue;
				if(j>0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
				if(k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
				if(l>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
			}
		}
		for(int a=0;a<=n/2;a++)for(int b=0;b<=n/2;b++){
			int c=n-a-b;if(c<0||c>n/2)continue;
			ans=max(ans,f[n][a][b]);
		}
		cout<<ans<<endl;
	}
	else{
		bool fl=0;
		for(int i=1;i<=n;i++)fl|=a[i][3];
		if(!fl){
			int ans=0;
			vector <int> v;
			for(int i=1;i<=n;i++){
				ans+=a[i][1],v.push_back(a[i][2]-a[i][1]);
			}
			sort(v.begin(),v.end());
			for(int i=1;i<=n/2;i++)ans+=v[n-i];	
			cout<<ans<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++)ans+=max({a[i][1],a[i][2],a[i][3]});
			cout<<ans<<endl;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>T;T--;)solve();return 0;
}
/* 
15:15 1~11 55pts
15:18 15&16 10pts
15:32 12~14 15pts
*/
