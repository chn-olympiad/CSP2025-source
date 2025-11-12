#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int ans=0;
string s[M],d[M],o,p;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(m*n*n<1000005)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>s[i]>>d[i];
		}
		for(int j=1;j<=m;j++)
		{
		cin>>o>>p;
		int jh=0;
		for(int i=1;i<=n;i++)
		{
			if(o.size()==s[i].size()&&p.size()==d[i].size())
			{
				for(int kk=1;kk<=n;kk++)
				{
					if(o[kk]!=s[i][kk]||p[kk]!=d[i][kk])
					{
						jh=1;
						break;
					}
				}
				if(jh==0)
				{
					ans++;
				}
			}
			
		}
		cout<<ans<<"\n";
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<"0\n";
	}
	return 0;
} 
