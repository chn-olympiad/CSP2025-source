#include<bits/stdc++.h>
using namespace std;
string a[10005],b[10005];
int l[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		l[i]=a[i].size();
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		int len=s1.size();
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=len-l[j];k++)
			{
				int fla=0;
				for(int ll=0;ll<len;ll++)
				{
					if(ll>=k&&ll<=k+l[j]-1)
					{
						if(s1[ll]!=a[j][ll-k]||s2[ll]!=b[j][ll-k])
						{
							fla=1;
							break;
						}
					}
					else
					{
						if(s1[ll]!=s2[ll])
						{
							fla=1;
							break;
						}
					}
				}
				if(!fla)
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
