#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string a;
int lena,b[1000010],bi;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	lena = a.length();
	for(int i = 0;i < lena;i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			bi++;
			b[bi] = (int)(a[i]-'0'); 
		}
	}
	sort(b+1,b+bi+1,cmp);
	for(int i = 1;i <= bi;i++)
		cout<<b[i];
	return 0;
}
