#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
string a[10010],b[10010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		
	}
	while (q--)
	{
		string c,d;
		cin>>c>>d;
		int cnt=0,h=0,st,en,ans=0;
		string s,s1;
		if (c.size()!=d.size())
		{
			cout<<0<<endl;
			continue;
		}
		for (int i=0;i<c.size();i++)
		{
			if (c[i]!=d[i])
			{
				if (c[i-1]==d[i-1]) 
				{
					h++;
					st=i;
					if (h==2)
					{
						cout<<0<<endl;
						continue;
					}
				}
				s=s+c[i];
				s1=s1+d[i];
				cnt++;
			}
			if (c[i]==d[i]&&c[i-1]!=d[i-1])
			{
				en=i;
			}
		}
		for (int i=1;i<=n;i++)
		{
			//cout<<s<<" "<<s1<<endl;
			if (s==a[i]&&s1==b[i]&&cnt==a[i].size())
			{
				ans++;
			}
			else if (c==a[i]&&d==b[i])
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
