#include<bits/stdc++.h>
using namespace std;
int n,q,l1,l2,ans,l,r;
string s1[200005],s2[200005],t1,t2;
bool kmp(int x)
{
	int bz1=-1,bz2=-1;
	int len1=s1[x].size(),len2=s2[x].size();
	for (int i=0;i<l1;i++)
	{
		bool bz=true;
		for (int j=0;j<len1;j++)
		{
			if (t1[i+j]!=s1[x][j])
			{
				bz=false;
				break;
			}
		}
		if (bz)
		{
			if (bz1==-1)
			{
				bz1=i;
			}
			else
			{
				return false;
			}
		}
	}
	for (int i=0;i<l2;i++)
	{
		bool bz=true;
		for (int j=0;j<len2;j++)
		{
			if (t2[i+j]!=s2[x][j])
			{
				bz=false;
				break;
			}
		}
		if (bz)
		{
			if (bz2==-1)
			{
				bz2=i;
			}
			else
			{
				return false;
			}
		}
	}
	if (bz1==bz2&&bz1!=-1)
	{
		if (bz1<=l&&bz1+len1-1>=r) return true;
		else return false;
	}
	return false;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for (int i=1;i<=q;i++)
	{
		cin>>t1>>t2;ans=0;l=1e9;r=-1;
		l1=t1.size(),l2=t2.size();
		for (int j=0;j<l1;j++)
		{
			if (t1[j]!=t2[j])
			{
				l=min(l,j);
				r=max(r,j);
			}
		}
		for (int j=1;j<=n;j++)
		{
			if (kmp(j)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
