#include<bits/stdc++.h>
using namespace std;

int n,q,ans;
string s[10005],qa,qb;
map<unsigned long long  ,string> mp;
unsigned long long  ha[10005][10005],p[800],haa[10005];

void HASH(int l,int r,string str)
{
	for(int i=0;i<str.length();i++) ha[l][r]+=str[i]-'0'+p[i];
}
void HASH2(int d,string str)
{
	for(int i=0;i<str.length();i++) haa[d]+=str[i]-'0'+p[i];
}

bool calc (string a)
{
	if(a.length()) return 1;
	return 0;
}

void dfs(string str)
{
	if(str==qb)
	{
		ans++;
		return ;
	}
	for(int i=1;i<=str.length();i++)
		for(int j=1;j<=i;j++)
		{
			
			unsigned long long nn=ha[j][i];
			if(calc(mp[ha[j][i]]))
			{
				int f=0;
				for(int k=j;k<=i;k++) 
					if(str[k-1]!=mp[ha[j][i]][k-j])
					{
						f=1;
						break;
					}
				if(f!=0)
				{
					string b;
					for(int k=1;k<j;k++) b=b+str[k-1];
					b=b+mp[ha[j][i]];
					for(int k=i+1;k<=qa.length();k++) b=b+str[k-1];
					unsigned long long asd=ha[j][i];
					ha[j][i]=asd;
				}
			}
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=n;i++) p[i]=p[i-1]*71;
	for(int i=1;i<=n;i++)
	{
		string sssss,ttt;
		cin>>ttt;
		cin>>sssss;
		HASH2(i,ttt);
		mp[haa[i]]=sssss;
	}
	cin>>qa>>qb;
	if(q)
	{
		for(int i=1;i<=qa.length();i++)
			for(int j=1;j<=i;j++)
			{
				string ss;
				for(int k=j;k<=i;k++) ss=ss+qa[k-1];				
				HASH(j,i,ss);
			}
		string newstr=qa;
		dfs(newstr);
	}
	cout<<ans;
	return 0;
}