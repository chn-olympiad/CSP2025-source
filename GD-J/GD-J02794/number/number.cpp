#include<bits/stdc++.h>
using namespace std;
int num[10];
string s;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);	
cin>>s;
for(int i=0;i<1000010;i++)
	{
	if(s[i]>='a'&&s[i]<='z')
		continue;		
	else if(s[i]>='0'&&s[i]<='9')
		{
		int z=s[i]-'0';
		num[z]++;	
		}
	else
		break;		
	}
for(int i=9;i>=0;i--)
	{
	for(int j=0;j<num[i];j++)
		{
		cout<<i;	
		}
	}
return 0;	
}
