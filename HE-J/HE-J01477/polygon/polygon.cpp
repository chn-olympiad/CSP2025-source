#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],num;
int aaa(int x)
{
	if(x==1)
	{
		return 1;
	}
	return x*aaa(x-1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++)
	{
		num+=aaa(n)/aaa(i);
	}
	cout<<num; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
