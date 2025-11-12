#include<bits/stdc++.h>
using namespace std;
int n,m,c[5000005],len1,len2,l,r,num1,num2,ans;
string s[200005][2],s1,s2;
int pipei(string a,string b)
{
	int x,sz1=(int)a.length()-1,sz2=(int)b.length()-1;
	for (int i=1;i<=sz2;++i)
	c[i]=0;
	x=0;
	for (int i=2;i<=sz2;++i)
	{
		while (x && b[i]!=b[x+1])
		x=c[x];
		if (b[i]==b[x+1])
		++x;
		c[i]=x;
	}
	x=0;
	for (int i=1;i<=sz1;++i)
	{
		while (x && a[i]!=b[x+1])
		x=c[x];
		if (a[i]==b[x+1])
		return i;
	}
	return 0;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>s[i][0]>>s[i][1];
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
	}
	while (m--)
	{
		cin>>s1>>s2;
		s1=' '+s1;
		s2=' '+s2;
		len1=s1.length()-1;
		len2=s2.length()-1;
		l=0;
		r=0;
		for (int i=1;i<=min(len1,len2);++i)
		if (s1[i]==s2[i])
		++l;
		else
		break;
		for (int i=len1,j=len2;i>0 && j>0;--i,--j)
		if (s1[i]==s2[j])
		++r;
		else
		break;
		ans=0;
		for (int i=1;i<=n;++i)
		if (len1-(int)s[i][0].length()==len2-(int)s[i][1].length())
		{
			num1=pipei(s1,s[i][0]);
			num2=pipei(s2,s[i][1]);
			if (num1 && num2 && num1==num2 && num1-1<=l && len1-num1-(int)s[i][0].length()+2<=r)
			++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
