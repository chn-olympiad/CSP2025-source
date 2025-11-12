#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
char c;
int a[1000010];
int k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c)
	{
		if(c>='0'&&c<='9')
		{
			k++;
			a[k]=c-='0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
