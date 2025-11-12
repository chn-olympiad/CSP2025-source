#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N=1e6+10;
string s;
int a[N],cnt;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++) printf("%d",a[i]);
	printf("\n"); 
	return 0;
} 
