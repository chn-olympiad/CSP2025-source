#include<bits/stdc++.h>
using namespace std;
int n,m,P,Q,R,k;
struct A4
{
	int p,q,r;
	bool operator<(const A4&x)const
	{
		return p>x.p;
	}
}b4[100002];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--)
	{
		P=Q=R=0;
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>b4[i].p>>b4[i].q>>b4[i].r;
		}
		sort(b4+1,b4+m+1);
		for(int i=1;i<=m/2;i++)
		{
			P+=b4[i].p;
		}
		for(int i=m/2+1;i<=m;i++)
		{
			P+=b4[i].q;
		}
		cout<<P<<endl;
	}
	return 0;
}
