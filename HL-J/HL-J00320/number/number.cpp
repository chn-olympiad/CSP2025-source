#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a;
long long chai[10000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long n1=1;
	while(a!=0)
	{
		chai[n1]=a%10;
		a=a/10;
		n1++;
	}
	sort(chai+1,chai+1+n1);
	for(long long i=n1;i>1;i--)
	{
		cout<<chai[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}