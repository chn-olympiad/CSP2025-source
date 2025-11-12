#include <bits/stdc++.h>

using namespace std;

template<class T>void Max(T &x,T y){ if (y>x) x=y;} 
const int N=500010,M=(1<<20)|1;
int n,k;
int w[N];
int lst[M];
int f[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> w[i];
		w[i]^=w[i-1];
	}
	
	memset(lst,-1,sizeof(lst)); lst[0]=0;
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if (lst[w[i]^k]!=-1) Max(f[i],f[lst[w[i]^k]]+1);
		lst[w[i]]=i;
	}
	cout << f[n] << "\n";
	
	return 0;
}
