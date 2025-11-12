#include <bits/stdc++.h>
using namespace std;
int num0=0,number[1000009];
int main(){  
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
for(int i=0;i<=s.size();i++)
{
	if(s[i]>='1'&&s[i]<='9')
	{
		number[i]=int(s[i]-48);
	}
	else if(s[i]=='0')
	{
		num0++;
	}
}
sort(number,number+s.size()+2);
for(int i=s.size()+1;i>=0;i--)
{
	if(number[i]==0) break;
	cout<<number[i];
}
for(int i=1;i<=num0;i++)
{
	cout<<0;
}
fclose(stdin);
fclose(stdout);
return 0;
}
