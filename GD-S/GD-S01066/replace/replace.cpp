#include<bits/stdc++.h>
using namespace std;
int n,g,t,k,ans;
string sx,sy;
map<string,string>f;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>g;
	for(int i=1;i<=n;++i)
	{
		cin>>sx>>sy;
		f[sx]=sy;
		f[sy]=sx;
	}
	while(g--)
	{
		ans=0,k=0;
		cin>>sx>>sy;
		if(sx.size()!=sy.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int z=sx.size();
		for(int i=0;i<z;++i) if(sx[i]!=sy[i]) k++;
		for(int i=0;i<z;++i)
		{
			t=0;
			for(int j=1;j<=z-i;++j)
			{
				if(f[sx.substr(i,j)]==sy.substr(i,j)) t+=j;
			}
			if(t==k||t==z) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
