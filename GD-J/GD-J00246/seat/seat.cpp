#include<bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _antirep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=1e4+5;

int n,m;
int a[N];

bool cmp(int x,int y)
{
	return x>y;
}

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	_rep(i,1,n*m) cin>>a[i];
	
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	int now=0;
	_rep(j,1,m)
	{
		if(j&1)
		{
			_rep(i,1,n)
			{
				now++;
				if(a[now]==x)
				{
					cout<<j<<" "<<i<<"\n";
					return 0; 
				}
			}
		} 
		else
		{
		 	_antirep(i,n,1)
		 	{
		 		now++;
		 		if(a[now]==x)
				{
					cout<<j<<" "<<i<<"\n";
					return 0; 
				}
			}
		}
	} 
	return 0;
} 
