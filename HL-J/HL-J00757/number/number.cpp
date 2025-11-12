#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool sp(int x,int y)
{
	return x>y;
};
int a[1000000];
int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int p=0;
	cin>>s;
	int num=s.size();
	
	for(int i=0;i<num;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[p]=s[i]-'0';
			p++;
		}
	}
	sort(a,a+p+1,sp);
	for(int i=0;i<p;i++)
	{
		cout<<a[i];
	}
	
	return 0;
}