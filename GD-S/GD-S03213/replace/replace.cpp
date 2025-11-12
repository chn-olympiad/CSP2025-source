#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>m;
map<string,bool>bo;
string a,b;
struct st
{
	string zc;
	int sta;
}zc[100005];
int zcn=0;
void find(string s)
{
	for(int i=1;i<=zcn;i++)
		zc[i].zc="";
	zcn=0;
	string l;
	for(int i=0;i<s.size();i++)
	{
		l="";
		for(int j=i;j<s.size();j++)
		{
			l+=s[j];
			if(bo[l]==1)
			{
				zcn++;
				for(int k=0;k<l.size();k++)
					zc[zcn].zc+=l[k];
				zc[zcn].sta=i;
				
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		m[a]=b,bo[a]=1;
	}
	while(q--)
	{
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<0<<endl;
			continue;
		}
		int fan=0;
		find(a);
		string a2="",l1="";
		for(int i=1;i<=zcn;i++)
		{
			a2=a;
			l1=m[zc[i].zc];
			int l2=0;
			for(int j=zc[i].sta;j<zc[i].sta+zc[i].zc.size();j++)
			{
				a2[j]=l1[l2];
				l2++;
			}
			if(a2==b) fan++;
		}
		cout<<fan<<endl;
	}
	return 0;
}
