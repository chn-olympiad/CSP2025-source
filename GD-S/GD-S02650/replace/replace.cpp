#include<bits/stdc++.h>
using namespace std;
const int mod1=1e9+7,mod2=1e9+9;
string s[200005];
string s_[200005];
string s1,s2;
long long int l[200005];
int n;
int q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		l[i]=s1.length();
		s[i]=s1;
		s_[i]=s2;
	}
	bool p;
	int ans;
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		ans=0;
		if(1e8/q>=s1.length()*s2.length()||q==1)
		for(int j=0;j<s1.length();j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(s1.length()<l[k])continue;
				p=1;
				for(int z=0;z<l[k];z++)
				{
					if(s1[j+z]!=s[k][z]||s2[j+z]!=s_[k][z])
					{
						p=0;
						break;
					}
				}
				if(p)
				{
					for(int z=0;z<j;z++)
					{
						if(s1[z]!=s2[z])
						{
							p=0;
							break;
						}
					}
					if(p)
					for(int z=l[k]+j;z<s1.length();z++)
					{
						if(s1[z]!=s2[z])
						{
							p=0;
							break;
						}
					}
				}
				if(p)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
