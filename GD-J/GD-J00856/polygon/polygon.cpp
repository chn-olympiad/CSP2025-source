#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod=998244353;
inline int Mod(int x) { return x<0 ? x+mod : (x>=mod ? x-mod : x); }
inline void adm(int &x,int y) { x=Mod(x+y); }
const int N=5010,M=5000;
int n;
int w[N];
int f[M+5];
int pw[N];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for (int i=1;i<=n;i++) cin >> w[i];
	sort(w+1,w+n+1);
	 
	pw[0]=1; for (int i=1;i<=n;i++) pw[i]=(ll)pw[i-1]*2%mod;
	f[0]=1; int ans=0;
	for (int i=1;i<=n;i++)
	{
		int res=pw[i-1];
		for (int j=0;j<=w[i];j++) adm(res,mod-f[j]);
		adm(ans,res);

		for (int j=M;j>=w[i];j--) adm(f[j],f[j-w[i]]);
	}
	cout << ans << "\n";
	
	return 0;
} 

/*
5
1 2 3 4 5

5
2 2 3 8 10
*/
