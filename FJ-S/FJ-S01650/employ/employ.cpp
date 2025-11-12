#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,cnt,lu,qi;
string a;
int v[600];
bool st[600];
void d(int x)
{
	if(x==n)
	{	
		if(lu>=m)cnt++;
		return ;
	}
	int xx=qi,yy=lu;
	for(int i=1;i<=n;i++)
	{
		qi=xx;
		lu=yy;
		if(st[i])continue;
		if(qi>=v[i])
		{
			st[i]=1;
			qi++;
			d(x+1);
			st[i]=0;
			continue;	
		}
		if(a[x]=='0')
		{
			qi++;
		}
		else lu++;
		st[i]=1;
		d(x+1);
		st[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++) cin>>v[i];
	d(0);
	cout<<cnt<<endl;
	return 0;
} 
