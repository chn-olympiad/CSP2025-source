#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
	string s1,s2;
}a[200050];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].s1>>a[i].s2;
	while(q--)
	{
		string c1,c2;
		cin>>c1>>c2;
		if(c1.size()!=c2.size())
		{
			cout<<0<<endl;
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int size=a[i].s1.size();
			for(int j=0;j<c1.size();j++)
			{
				if(c1.substr(j,size)==a[i].s1)
				{
					c1.substr(j,size)=a[i].s2;
					string m;
					for(int k=0;k<j;k++)
						m+=c1[k];
					m+=a[i].s2;
					for(int k=j+size;k<c1.size();k++)
						m+=c1[k];
					if(m==c2)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
