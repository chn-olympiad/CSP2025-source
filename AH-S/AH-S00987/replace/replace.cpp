#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s1,s2;
}s[200010];
string st1,st2;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i].s1>>s[i].s2;
	}	
	while(q--)
	{
		cin>>st1>>st2;
		if(st1.size()!=st2.size()) 
		{
		 	cout<<0<<'\n';
		 	continue;
		}
		int l=st1.size(),ans=0;
		for(int i=0;i<l;i++)
		{
			string str="";
			for(int j=i;j<l;j++)
			{
				str+=st1[j];
				for(int k=1;k<=n;k++)
				{
					if(str==s[i].s1)
					{
						string sf=st1;
						for(int g=i,h=0;g<=j;g++,h++) sf[i]=s[i].s1[h];
						if(sf==st2) ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
