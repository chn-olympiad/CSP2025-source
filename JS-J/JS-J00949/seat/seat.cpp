#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,a[N],a1,cnt;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)
		cin>>a[i];
	a1=a[1];
	stable_sort(a+1,a+n*m+1);
	cnt=n*m;
	for(int i=1;i<=m;++i)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;++j)
			{
				if(a[cnt--]==a1)
				{
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[cnt--]==a1)
				{
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
	}
    return 0;
}
