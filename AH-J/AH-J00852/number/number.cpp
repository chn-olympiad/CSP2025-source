#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,g,h,i,j,k,l,ab=1;
string s;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(i=0,i<=s.size();i++)
{                 
if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
num++;
	if(s[i]=='0')
	a++;
	if(s[i]=='1')
	b++;
	if(s[i]=='2')
	c++;
	if(s[i]=='3')
	d++;
	if(s[i]=='4')
	e++;
	if(s[i]=='5')
	f++;
	if(s[i]=='6')
	g++;
	if(s[i]=='7')
	h++;
	if(s[i]=='8')
	k++;
	if(s[i]=='9')
	l++;
}
return 0;
}
