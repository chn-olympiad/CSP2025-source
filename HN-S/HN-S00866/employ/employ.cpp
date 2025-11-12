#include <bits/stdc++.h>

#define fst first
#define sec second
#define pb push_back
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using p_q = priority_queue<int>;

const int N = 550;
const ll P = 998244353;

ll f[N][N],hd[N],c[N],sm[N],g[N][N];
ll jc[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		hd[i]=s[i-1]-'0';sm[i]=sm[i-1]+hd[i];
	}
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%P;
	}
	ll qwq=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];if(c[i]==0) qwq++;
	}
	if(sm[n]==n){
		cout<<jc[n]<<endl;return 0;
	}
	/*f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int len=1;len<=i;len++){
				
			}
		}
	}*/
	cout<<0<<endl;

	return 0;
}

