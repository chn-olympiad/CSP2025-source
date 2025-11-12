#include<bits/stdc++.h>
using namespace std;
int n,q,l,s,z;
string s1[200001],s2[200001],bz1[200001],bz2[200001],q1,q2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		s=0;
		z=0;
		bool bl=1;
		cin>>s1[i]>>s2[i];
		l=s1[i].length();
		for(int j=0;j<l;j++)
		{
			if(s1[i][j]!=s2[i][j]&&bl)
			{
				s=j;
				bl=0;
			}
			if(s1[i][j]!=s2[i][j]&&!bl)
				z=j;
		}
		if(!z)
		z=l-1;
		for(int j=s;j<=z;j++)
		{
			bz1[i]+=s1[i][j];
			bz2[i]+=s2[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>q1>>q2;
		if(q1.length()!=q2.length())
		{
			cout<<0<<endl;
			continue; 
		}
		else
		{
			s=0;
			z=0;
			string qb1,qb2;
			int ans=0;
			bool bl=1;
			l=q1.length();
		for(int j=0;j<l;j++)
		{
			if(q1[j]!=q2[j]&&bl)
			{
				s=j;
				bl=0;
			}
			if(q1[j]==q2[j]&&!z&&!bl)
				z=j-1;
		}
		if(!z)
		z=l-1;
		for(int j=s;j<=z;j++)
		{
			qb1+=q1[j];
			qb2+=q2[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(qb1==bz1[j]&&qb2==bz2[j])
			ans++;
		}
		cout<<ans<<endl;
		}
	}
	return 0;
}
