#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n;
long long a[MAXN][4];
int b[MAXN],c[4];
long long sum;
vector<int>tmp;
void solve(){
	cin>>n;
	sum=0;
	c[1]=c[2]=c[3]=0;
	for(int i=1;i<=n;++i)cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;++i){
		auto mx=max(a[i][1],max(a[i][2],a[i][3]));
		sum+=mx;
		for(int j=1;j<=3;++j)if(a[i][j]==mx){
			b[i]=j;
			++c[j];
			break;
		}
	}
	for(int j=1;j<=3;++j)if(c[j]>n/2){
//		cerr<<n<<' '<<j<<'\n';
		int t=c[j]-n/2;
		tmp.clear();
		for(int i=1;i<=n;++i)if(b[i]==j){
			long long mx=0;
			for(int k=1;k<=3;++k)if(k!=j)mx=max(mx,a[i][k]);
			tmp.emplace_back(a[i][j]-mx);
		}
		sort(tmp.begin(),tmp.end());
		for(int i=0;i<t;++i)sum-=tmp[i];
	}
	cout<<sum<<'\n';
//	cerr<<"finished\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	tmp.reserve(1e5);
	int t;cin>>t;while(t--)solve();
}
