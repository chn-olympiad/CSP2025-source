#include<bits/stdc++.h>
using namespace std;
char a[10005];
char b[10005];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
	int k=0;
	int n=strlen(a);
for(int i=0;i<=n;i++)
{
	if(48<=a[i]&&a[i]<=57)
	{
		b[k]=a[i];
		k++;
	}
}

sort(b,b+n,cmp);
for(int i=0;i<n;i++)
{
	cout<<b[i];
}
	return 0;
}
 
 
