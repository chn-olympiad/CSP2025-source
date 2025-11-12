#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,q,a,b,c,d,e,f,g,h,i,j;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&& s[i]<='9')
			q+= s[i];
	}
	for(int j=0;j<=q.size();j++)
	{
		if(q[j]=='1')
			a+=q[j];
		else if(q[j]=='2')
			b+=q[j];
		else if(q[j]=='3')
			c+=q[j];
		else if(q[j]=='4')
			d+=q[j];
		else if(q[j]=='5')
			e+=q[j];
		else if(q[j]=='6')
			f+=q[j];
		else if(q[j]=='7')
			g+=q[j];
		else if(q[j]=='8')
			h+=q[j];
		else if(q[j]=='9')
			i+=q[j];
	}
	cout  << i;
	cout  << h;
	cout  << g;
	cout  << f;
	cout  << e;
	cout  << d;
	cout  << c;
	cout  << b;
	cout  << a;
	for(int g=0;g<=q.size();g++)
	{
		if(q[g]=='0')
			cout << "0";
	}
	return 0;
}
