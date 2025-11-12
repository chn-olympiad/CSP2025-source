#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
const int maxA=1e6+5;
int a[maxA];
int j=0,endZui=0;
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]+=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j+1)
	for(int i=j;i>=0;i--)
	{
		char ss=a[i]='0';
		end
		cout<<a[i]<<" ";
	}
	
} 
