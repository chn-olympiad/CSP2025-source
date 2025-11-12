#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[1000500][3];
string t[1000050][3];
string num1[1000500],num2[1000500];
map<string,int> qp;
bool pd(string a1,string a2)
{
	for(int i=0;i<a1.size();i++)
	{
		int ff=0;
		for(int j=0;j<a2.size();j++)
		{
			if(a1[i+j]!=a2[j]) 
			{
				ff=1;
				break;
			}
		}
		if(ff==0) return true;
	}
	return false;
}
string fun(int qo)
{
	string au="",ua="";
	for(int i=qo;i>0;i/=10) au+=char((i%10)+'0');
	for(int i=au.size()-1;i>=0;i--) ua+=au[i];
	return ua;
}
int l1,l2;
int i1[1000500],i2[1000500];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2];
	for(int i=1;i<=n;i++) l1+=s[i][1].size()*2;
	for(int i=1;i<=q;i++) l2+=t[i][1].size()+t[i][2].size();
	for(int i=1;i<=n;i++)
	{
		int l=-1,r=0;
		for(int j=0;j<s[i][1].size();j++)
		{
			if(s[i][1][j]=='b') i1[i]=j;
			if(s[i][2][j]=='b') i2[i]=j;
			if(s[i][1][j]!=s[i][2][j])
			{
				r=j;
				if(l==-1) l=j;
			}
		}
		for(int j=l;j<=r;j++) num1[i]+=s[i][1][j];
		for(int j=l;j<=r;j++) num2[i]+=s[i][2][j];
		string ak=num1[i]+num2[i];
		string ol=fun(i1[i]),lo=fun(i2[i]);
		ak+=ol;
		ak+=lo;
		if(l1>=1e5||l2>=1e5) qp[ak]++;
	}
	if(l1>=1e5||l2>=1e5)
	{
		for(int i=1;i<=q;i++)
		{
			if(t[i][1].size()!=t[i][2].size())
			{
				printf("%d\n",0);
				continue; 
			}
			int l=-1,r=0;
			int ip1=0,ip2=0;
			for(int j=0;j<t[i][1].size();j++)
			{
				if(t[i][1][j]=='b') ip1=j;
				if(t[i][2][j]=='b') ip2=j;
				if(t[i][1][j]!=t[i][2][j])
				{
					if(l==-1) l=j;
					r=j;
				}
			}
			string s1="",s2="";
			for(int j=l;j<=r;j++) s1+=t[i][1][j];
			for(int j=l;j<=r;j++) s2+=t[i][2][j];
			string lo=fun(ip1),ol=fun(ip2);
			string up=s1+s2;
			up+=lo;
			up+=ol;
			printf("%d\n",qp[up]);
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		if(t[i][1].size()!=t[i][2].size())
		{
			printf("0\n");
			continue; 
		}
		int l=-1,r=0;
		for(int j=0;j<t[i][1].size();j++)
		{
			if(t[i][1][j]!=t[i][2][j])
			{
				if(l==-1) l=j;
				r=j;
			}
		}
		string s1="",s2="";
		int ans=0;
		for(int j=l;j<=r;j++) s1+=t[i][1][j];
		for(int j=l;j<=r;j++) s2+=t[i][2][j];
		for(int j=1;j<=n;j++)
		{
			if(num1[j]==s1&&num2[j]==s2)
			{
				if(pd(t[i][1],s[j][1])&&pd(t[i][2],s[j][2]))
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);	
	}	
	return 0;
}
