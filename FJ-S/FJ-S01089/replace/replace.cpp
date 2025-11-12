#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
string ts[200005][2];
int bj[200005][5],bjj[9];
string t[2];
string tep(string a,string b,int bjd,int xu)
{
	int la=a.size(),lb=b.size();
	int l=la,r=-1;
	for(int i=0;i<la;i++)
		if(a[i]!=b[i])
			l=i;
	for(int i=la-1;i>=0;i--)
		if(a[i]!=b[i])
			r=i;
	string tt="";
	for(int i=l;i<=r;i++)
		tt+=a[i];
	if(bjd==1)
	{
		bj[xu][1]=l;
		bj[xu][2]=r;
	}
	if(bjd==2)
	{
		bj[xu][3]=l;
		bj[xu][4]=r;
	}
	if(bjd==3)
	{
		bjj[1]=l;
		bjj[2]=r;
	}
	if(bjd==4)
	{
		bjj[3]=l;
		bjj[4]=r;
	}
	return tt;
}
void replace(string a,string b)
{
	int ans=0;
	string ta=tep(a,b,3,0),tb=tep(b,a,4,0);
	for(int i=1;i<=n;i++)
	{
		if(ta==ts[i][0]&&tb==ts[i][1])
		{
			bool flag=0;
			if(!flag)
			ans++;
		}
	}
	cout<<ans;
	return ;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		ts[i][0]=tep(s[i][0],s[i][1],1,i);
		ts[i][1]=tep(s[i][1],s[i][0],2,i);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[0]>>t[1];
		replace(t[0],t[1]);
	}
	return 0;
}
/**/
