#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000001]; //表示小 X 给小 R 的字符串.
	int a[1000001];  //shu
	for(int i = 1;i<=1000000;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i] = s[i];
		}
	}
	for(int i = 1;i<=1000001;i++)
	{
		if(a[i]<a[i+1])
		{
			a[i]=a[i+1];
			
		}
	}
	for(int i = 1;i <= 1000001;i++)
	{
		cout << a[i];
	}
	return 0;
}
