#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define TNF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,t,mx=-TNF;
struct s{
	int a,b,c;
}v[100010];
bool st[100010]; 
int aa=0,bb=0,cc=0;
void d(int x,int y,int fa)
{
	if(x==n+1)
	{
		mx=max(y,mx);
		return ;
	}
	for(int i=fa;i<=n;i++)
	{
		if(st[i])continue;
		st[i]=1;
		if(aa<n/2)
		{
			aa++;
			d(x+1,y+v[i].a,i);
			aa--;
		}
		if(bb<n/2)
		{
			bb++;
			d(x+1,y+v[i].b,i);
			bb--;
		}
		if(cc<n/2)
		{
			cc++;
			d(x+1,y+v[i].c,i);
			cc--;
		}
		st[i]=0;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		aa=0;
		bb=0;
		cc=0;
		mx=-TNF;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i].a>>v[i].b>>v[i].c;
		}
		d(1,0,1);
		cout<<mx<<endl;
	}
	return 0;
} 
