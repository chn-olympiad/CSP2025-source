#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;
int a[1000001],num=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
				if(s[i]=='0')
				{
					a[num]=0;
					num++;
				}
				if(s[i]=='1')
				{
					a[num]=1;
					num++;
				}
				if(s[i]=='2')
				{
					a[num]=2;
					num++;
				}
				if(s[i]=='3')
				{
					a[num]=3;
					num++;
				}
				if(s[i]=='4')
				{
					a[num]=4;
					num++;
				}
				if(s[i]=='5')
				{
					a[num]=5;
					num++;
				}
				if(s[i]=='6')
				{
					a[num]=6;
					num++;
				}
				if(s[i]=='7')
				{
					a[num]=7;
					num++;
				}
				if(s[i]=='8')
				{
					a[num]=8;
					num++;
				}
				if(s[i]=='9')
				{
					a[num]=9;
					num++;
				}
				
		}
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num-1;i++)
		cout<<a[i];
	return 0;
}
