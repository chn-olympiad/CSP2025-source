#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y)
{
		return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),j=1;
	if(len==1)
	{
		cout<<s;
		return 0;
	}
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++)
		cout<<a[i];
	return 0;
}
