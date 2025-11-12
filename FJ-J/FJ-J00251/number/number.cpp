#include<bits/stdc++.h>
using namespace std;
int s1[1000100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size(),j=0;
	for(int i=0;i<a;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			s1[j]=s[i]-'0'+1;
			j++;
		}
	}
	sort(s1,s1+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<s1[i]-1;
	}
	return 0;
} 
