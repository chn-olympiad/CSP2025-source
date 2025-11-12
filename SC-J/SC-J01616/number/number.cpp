#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
string s;
int a[1000050];
int cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0')
		{
			cnt++;
			a[cnt]=0;
		}
		if(s[i]=='1')
		{
			cnt++;
			a[cnt]=1;
		}
		if(s[i]=='2')
		{
			cnt++;
			a[cnt]=2;
		}
		if(s[i]=='3')
		{
			cnt++;
			a[cnt]=3;
		}
		if(s[i]=='4')
		{
			cnt++;
			a[cnt]=4;
		}
		if(s[i]=='5')
		{
			cnt++;
			a[cnt]=5;
		}
		if(s[i]=='6')
		{
			cnt++;
			a[cnt]=6;
		}
		if(s[i]=='7')
		{
			cnt++;
			a[cnt]=7;
		}
		if(s[i]=='8')
		{
			cnt++;
			a[cnt]=8;
		}
		if(s[i]=='9')
		{
			cnt++;
			a[cnt]=9;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	cout<<a[i];
	return 0;
 } 