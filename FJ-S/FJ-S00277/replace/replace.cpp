#include<iostream>
#include<string>
using namespace std;
string t1,t2,s1[200010],s2[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>t1>>t2;
		for(int j=0;j<t1.length();j++)
		{
			for(int k=1;k<=n;k++)
			{
				bool flag=1;
				string t=t1;
				for(int l=0;l<s1[k].length();l++)
					if(t[j+l-1]==s1[k][l])
						t[j+l-1]=s2[k][l];
					else
						flag=0;
				if(flag&&t==t2)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
