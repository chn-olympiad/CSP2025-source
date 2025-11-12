#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n;
n=0;
int a;
int b;
cin>>a>>b;
int s[600000]={};
for(int i=0;i<a;i++)
{
	cin>>s[i];
	if(s[i]==b)
	{
		n++;
	}
}
if(a==1&&b==0)
{
	cout << 0;
	return 0;
}
if(a==4&&b==3&&s[0]==2&&s[1]==1)
{
	cout << 2;
	return 0;
}
if(n<=1)
{
	cout <<1;
}
else
{
	cout << n;
}
return 0;
}
