#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int a[1000002]={};int t=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	
	cin>>s;
	
	for(int i=0;i<int(s.size());i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[t]=int(s[i]-'0');
			t++;
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>1;i--)
	{
		printf("%d",a[i]);
	}
	
	return 0;
}
