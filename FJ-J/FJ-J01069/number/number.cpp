#include<bits/stdc++.h>
using namespace std;
char a[2001000];
long long n,b[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>a;
	n=strlen(a);
	for(long long i=0;i<n;i++)
		if(a[i]>='0'&&a[i]<='9')
			b[a[i]-'0']++;
	for(long long i=9;i>=0;i--)
		for(long long j=1;j<=b[i];j++)
			printf("%lld",i);
	printf("\n");
	return 0;
}
