#include<bits/stdc++.h>
using namespace std;
int n,m,t,a,b,fx,f[1010];
bool cmp(int x,int y){ return x>y; }
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>f[i];
	}
	t=f[1];
	a=0,b=1;
	sort(f+1,f+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)
	{
		if(a==n&&fx==0) b++,fx=1;
		else if(a==1&&fx==1) b++,fx=0;
		else if(fx==1) a--;
		else a++;
		if(f[i]==t)
		{
			cout<<b<<' '<<a;
			return 0;
		}
	}
	return 0;
}
