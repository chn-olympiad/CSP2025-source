#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cmath>
#include<cfloat>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l = s.size(),sum = 0;
	for(int i = 0;i < l;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[sum] = int(s[i]) - 48; 
			sum++;
		}
	}
	sort(a,a + sum);
	bool v = false;
	for(int i = sum-1;i >= 0;i--)
	{
		if(v)	printf("%d",a[i]);
		else if(a[i] != 0)
		{
			printf("%d",a[i]);
			v = 1;
		}
	}
	if(v == 0) printf("%d",0);
	return 0;
} 