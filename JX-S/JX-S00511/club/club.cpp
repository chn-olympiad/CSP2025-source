#include <bits/stdc++.h>
using namespace std;
int t,n,bottle,a,b,c,sum,maxn=-1,maxx=-1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a >> b >> c;
			if(a>maxn)
			{
				maxx=maxn;
				maxn=a;
			}
			cout << maxn+maxx << endl;
		}
	}	
	return 0;
}
