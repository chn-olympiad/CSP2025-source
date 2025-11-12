#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string a[200005],b[200005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		if(x.length()!=y.length()) 
		{
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<x.length()-a[i].length()+1;j++)
			{
				if(x[j]==a[i][0])
				{
					int t=j+1,u=1;
					bool flag=true;
					while(1)
					{
						if(x[t]!=a[i][u]) break;
						else if(u==a[i].length()) break;
						else t++,u++;
					}
					if(flag)
					{
						bool h=true;
						for(int k=0;k<y.length();k++)
						{
							if(k>=j&&k<a[i].length()+j)
							{
								if(y[k]!=b[i][k-j]) 
								{
									h=false;
									break;
								}
							}
							else if(x[k]!=y[k]) 
							{
								h=false;
								break;
							}
						}
						if(h) ans++;
					}
				} 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
