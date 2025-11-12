#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char s[1000005];
int main()
{
	freopen("number.in",r,stdin);
	freopen("number.out",w,stdout);
	cin>>s;
	long long n=1000005;
	sort(s+0,s+n);
	for(long long i=n-1;i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cout<<s[i];
		}
	}

	return 0;	
} 
