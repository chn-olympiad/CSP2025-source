#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005],c,d;
int n,ans,m,k,jcbl;
int eee(string s,string e,string s1,string e1,int eee)
{
	bool eeeee=0;
	eee=0;
	for(int i=0;i<int(s.size());i++)
	{
		if(eeeee==1)
		{
			if(s[i]!=s1[i])
			{
				return 0;
			}
		}
		else {
		for(int j=i;j<int(e.size())+i&&j<int(s.size());j++)
		{
			if(s[j]!=e[j-i]||s1[j]!=e1[j-i]){
			break;
			}
			if(j+1==int(e.size())+i)
			{
				eeeee=1;
				i=j;
				break;
			}
		}}
		if(eeeee==0&&s[i]!=s1[i])
		{
			return 0;
		}
	}
	return eeeee;
}
int ee2(string s,string e,int eee)
{
	for(int i=eee;i<int(s.size());i++)
	{
		if(s[i]!=e[i])
		return 0;
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>c>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(eee(c,a[i],d,b[i],0))
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
