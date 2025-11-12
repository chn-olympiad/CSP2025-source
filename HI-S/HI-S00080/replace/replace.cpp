#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n],s2[n],t1[q],t2[q],x,y,z,y1,s3[n];
	int cnt=0;
	int ky;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];	
	}
	for(int j=1;j<=q;j++)
	{
		cin>>t1[j]>>t2[j];
	}
	for(int i=1;i<=n;i++)
	{
		if(y==s1[i])
		{
			y=y1=s2[i]; 
		}
		if(s1[i]==x+y+z)
		{
			s3[i]=x+y1+z;
			ky=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
		{
			if(x+z+y!=s1[i]||i!=ky)
			{
				if(t1[j]==t2[j])
				{
					cnt++;
				}
			}
			cout<<cnt;
		}
	}
	return 0;
}

