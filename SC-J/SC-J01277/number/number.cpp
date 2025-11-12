#include<bits/stdc++.h>
using namespace std;
string s;
int a[9999999];
char b[9999999];
int main()
{
	int j=1;
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4')
		{
			b[j]=s[i]; 
			j++;
		}
		
	}
	sort(b+1,b+j);
	for(int i=j-1;i>=1;i--)
	{
		cout<<b[i];
	}
	return 0;
} 