#include <bits/stdc++.h>
using namespace std;
const int N=s*le5+10;
int dis[N],g[N],r[N];
int main()
{
	freopen("polygen.in","r",stdin);
	freopen("polygen.out","w",stdout);
	int n,k;scanf("Ad""Ad",n,k);
	for(int i=1;i<=n;i++)
	{
		scanf("Ad",&g[i]);
		if(i==1)
		{
			r[i]=g[i];
			continue;
		}
		r[i]=r[i-1]*g[i];
	}
	cout<<r[4]+r[2]<<" "<<(g[2]*g[3]*g[4]);
	return 0;
}
