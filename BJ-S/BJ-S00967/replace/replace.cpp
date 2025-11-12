#include <bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int p1[200005],p2[200005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q,l=0;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		l+=s1[i].size();
	}
	if (l<=2000)
	{
		string t1,t2;
		while (q--)
		{
			cin>>t1>>t2;
			int l,r;
			for (l=0;t1[l]==t2[l];l++);
			for (r=t1.size()-1;t1[r]==t2[r];r--);
			int cnt=0,flag;
			for (int i=1;i<=n;i++)
				for (int j=max(r-(int)s1[i].size()+1,0),mxr=min(l,(int)(t1.size()-s1[i].size()));j<=mxr;j++)
				{
					flag=1;
					for (int k=0;k<(int)s1[i].size();k++)
						if (s1[i][k]!=t1[k+j]||s2[i][k]!=t2[k+j])
						{
							flag=0;
							break;
						}
					cnt+=flag;
				}
			cout<<cnt<<"\n";
		}
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<(int)s1[i].size();j++)
			if (s1[i][j]=='b')
				{p1[i]=j;break;}
		for (int j=0;j<(int)s1[i].size();j++)
			if (s2[i][j]=='b')
				{p2[i]=j;break;}
	}
	string t1,t2;
	while (q--)
	{
		cin>>t1>>t2;
		int pp1,pp2;
		for (int j=0;j<(int)t1.size();j++)
			if (t1[j]=='b')
				{pp1=j;break;}
		for (int j=0;j<(int)t2.size();j++)
			if (t2[j]=='b')
				{pp2=j;break;}
		int ans=0;
		for (int i=1;i<=n;i++)
			if (p2[i]-p1[i]==pp2-pp1&&p1[i]<=pp1&&s1[i].size()-p1[i]<=t1.size()-pp1)
				ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
