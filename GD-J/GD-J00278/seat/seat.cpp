#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define ll long long
using namespace std;
int a[15][15],s[1145];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int tgt;
	rep(i,1,n*m) cin>>s[i];
	tgt=s[1];
	sort(s+1,s+n*m+1,cmp);
	int cur=1;
	rep(i,1,m)
	{
		if(i%2==1)
		{
			rep(j,1,n)
			{
				if(s[cur]==tgt)
				{
					cout<<i<<' '<<j;return 0;
				}
				cur++;
			}
		}
		else
		{
			ir(j,1,n)
			{
				if(s[cur]==tgt)
				{
					cout<<i<<' '<<j;return 0;
				}
				cur++;
			}
		}
	}
	return 0;
 }

