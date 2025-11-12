#include <bits/stdc++.h>
using namespace std;
char x[10000005];
int a[10000005];
long long k=0;
int main()
{

	cin>>x;
	for(int i=0;x[i];i++)
	{
		if(x[i]>='0'&&x[i]<='9')a[k++]=x[i]-'0';
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--)
	{
		cout<<a[i];
	}

	return 0;
}
