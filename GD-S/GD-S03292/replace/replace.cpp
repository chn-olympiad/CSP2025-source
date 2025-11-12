#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,int>b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		x+=y;
		b[x]++;
	}
	while(q--)
	{
		string x,y,xf,yf;
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int xl=x.size()-1,l=0,r=xl,ans=0;
		while(x[l]==y[l]) l++;
		while(x[r]==y[r]) r--;
		for(int i=l;i<=r;i++) xf+=x[i],yf+=y[i];
		for(int i=l;i>=0;i--)
		{
			if(i<l) xf=x[i]+xf,yf=y[i]+yf;
			string xx=xf,yy=yf;
			for(int j=r;j<=xl;j++)
			{
				if(j>r) xx+=x[j],yy+=y[j];
				string z=xx+yy;
				ans+=b[z];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
