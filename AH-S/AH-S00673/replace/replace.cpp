#include <bits/stdc++.h>
using namespace std;
struct dic
{
	string a,b;
}th[200005];
string tihuan(string s,string a,string b)
{
	for(int i=s.find(a);i<=s.find(a)+a.size();i++)
	{
		s[i]=b[i];
	}
	return s;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>th[i].a>>th[i].b;
	}
	for(int i=1;i<=q;i++)
	{
		int cnt=0;
		dic sth;
		cin>>sth.a>>sth.b;
		for(int j=1;j<=n;j++)
		{
			if(sth.a.find(th[i].a)!=-1)
			{
				//string sb="",sa="",st="";
				//for(int k=0;k<=sth.a.find(th[i].a);k++)
				//{
				//	sb+=sth.a[k];
				//}
				//for(int k=sth.a.find(th[i].a)+th[i].a.size();k<=sth.a.size()+1;k++)
				//{
				//	sa+=sth.a[k];
				//}
				//st=sb+th[i].b+sa;
				string s=sth.a;
				s=tihuan(s,th[i].a,th[i].b);
				if(s==sth.b)
				{
					cnt++;
				}
				
			}
		}
		cout<<cnt<<endl;
	}
}
