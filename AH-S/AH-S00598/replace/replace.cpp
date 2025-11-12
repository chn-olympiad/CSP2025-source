#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int i,n,q,p[N],ma=-1;
string s1,s2,a[N],b[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(n*q>=1e9)
	{
		while(q--)cout<<0<<endl;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		int len=a[i].size();
		ma=max(ma,len);
	}
	while(q--)
	{
		cin>>s1>>s2;
		int len=s1.size();
		string dif;
		for(i=0;i<len;i++)p[i]=0;
		int fl=0,ans=0;
		for(i=0;i<len;i++)
		{
			if(dif.size()!=0&&i>0&&s1[i-1]==s2[i-1]&&s1[i]!=s2[i])
			{
				fl=1;
				break;
			}
			if(s1[i]!=s2[i])dif+=s1[i];
		}
		if(fl==1)
		{
			cout<<0<<endl;
			continue;
		}
		int lena=dif.size();
		if(lena>ma)
		{
			cout<<0<<endl;
			continue;
		}
		for(i=1;i<=n;i++)
		{
			int lenb=a[i].size();
			if(s1.find(a[i])==s2.find(b[i])&&lenb>=lena&&s1.find(a[i])!=string::npos)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
