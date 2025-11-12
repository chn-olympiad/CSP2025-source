#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
string s1[200005],s2[200005];
string t1[200005],t2[200005];
int f(int ss,int tt)
{
	int cnt=0;
	if(t1[tt].size()!=t2[tt].size())return 0;
	for(int i=0;i<t1[tt].size();i++)
	{
		bool flag=1;
		for(int j=0;j<s1[ss].size();j++)
		{
			if(j+i>=t1[tt].size())
			{
				flag=0;
				break;
			}
			if(t1[tt][j+i]!=s1[ss][j])
			{
				flag=0;
				break;
			}
		}
		if(flag==0)continue;
		for(int j=0;j<s2[ss].size();j++)
		{

			if(t2[tt][j+i]!=s2[ss][j])
			{
				flag=0;
				break;
			}
		}
		for(int j=0;j<t1[tt].size();j++)
		{
			if(j<i||j>=i+s2[ss].size())
			{
				if(t1[tt][j]!=t2[tt][j])
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==1)
		{
			cnt++;
			//cout<<ss<<' '<<tt<<' '<<i<<endl;
		}

	}
	return cnt;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			ans+=f(j,i);
		}
		cout<<ans<<endl;
	}
}
