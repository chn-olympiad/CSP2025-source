#include<bits/stdc++.h>
using namespace std;
long long n=1,m=1,c[100000005];
char a[100000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	while(n<=1000000000000)
	{
		cin>>a[n];
		if(a[n]>='0' && a[n]<='9')
		{
			c[m]=a[n]-'0';
			m++;
		}
		n++;
	}
	sort(c+1,c+m,cmp);
	for(long long i=1;i<=m-1;i++)
	{
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}