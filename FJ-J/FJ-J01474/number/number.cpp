#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s;
int a[15];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[s[i]-'0']+=1;
	}
	for(int i=9;i>=0;)
	{
		if(a[i]>0){cout<<i;a[i]--;}
		else if(a[i]==0)i--;
	}
	
	return 0;
 } 
