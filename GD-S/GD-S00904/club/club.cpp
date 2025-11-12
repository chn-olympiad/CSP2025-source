#include<bits/stdc++.h>
using namespace std;
const int M=100010;
int t,n,x,y,z,a[M],ka,b[M],kb,c[M],kc,s;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=ka=kb=kc=0;
		for(register int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			if(x>=y&&x>=z)
			{
				s+=x;
				if(y>z)a[++ka]=x-y;
				else a[++ka]=x-z;
			}
			else if(y>=x&&y>=z)
			{
				s+=y;
				if(x>z)b[++kb]=y-x;
				else b[++kb]=y-z;
			}
			else
			{
				s+=z;
				if(x>y)c[++kc]=z-x;
				else c[++kc]=z-y;
			}
		}
		if(ka>(n>>1))
		{
			sort(a+1,a+ka+1);
			for(register int i=ka-(n>>1);i;i--)
				s-=a[i];
		}
		else if(kb>(n>>1))
		{
			sort(b+1,b+kb+1);
			for(register int i=kb-(n>>1);i;i--)
				s-=b[i];
		}
		else if(kc>(n>>1))
		{
			sort(c+1,c+kc+1);
			for(register int i=kc-(n>>1);i;i--)
				s-=c[i];
		}
		cout<<s<<'\n';
	}
	return 0;
}
