#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[1000005];
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			t++;
			char t1=s[i];
			int t2=t1-48;
			a[t]=t2;
		}
	}
	sort(a+1,a+s.size(),cmp);
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
} 