#include <bits/stdc++.h>
using namespace std;
string s,s1="";
string n;
string j,b,q,l,w,si,sa,e,k,nin;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n+=s[i];
		}
	}
	for(int i=0;i<=n.size();i++)
	{
		if(n[i]=='9')
		{
		    j+=n[i];	
		}
		else if(n[i]=='8')
		{
			b+=n[i];
		}
		else if(n[i]=='7')
		{
			q+=n[i];
		}
		else if(n[i]=='6')
		{
			l+=n[i];
		}
		else if(n[i]=='5')
		{
			w+=n[i];
		}
		else if(n[i]=='4')
		{
			si+=n[i];
		}
		else if(n[i]=='3')
		{
			sa+=n[i];
		}
		else if(n[i]=='2')
		{
			e+=n[i];
		}
		else if(n[i]=='1')
		{
			k+=n[i];
		}
		else{
			nin+=n[i];
		}
	}
	s1+=j;
	s1+=b;
	s1+=q;
	s1+=l;
	s1+=w;
	s1+=si;
	s1+=sa;
	s1+=e;
	s1+=k;
	s1+=nin;
	cout<<s1;
	return 0;
}
