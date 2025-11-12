#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[2005],s1[2005],t1,t2;
bool c1[2005],c2[2005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>s1[i];
	while(q--)
	{
		int cnt=0;
		cin>>t1>>t2;
		string t_="";
		for(int i=0;i<t1.size();i++)
		{
			for(int j=1;j<t1.size();j++)
			{
				t_+=t1[j];
				for(int k=1;k<=n;k++)if(s[k]==t_)c1[k]=1;
			}
		}
		t_="";
		for(int i=0;i<t2.size();i++)
		{
			for(int j=1;j<t2.size();j++)
			{
				t_+=t2[j];
				for(int k=1;k<=n;k++)if(s1[k]==t_)c2[k]=1;
			}
		}
		for(int i=1;i<=n;i++)if(c1[i]==c2[i]&&c1[i])cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
