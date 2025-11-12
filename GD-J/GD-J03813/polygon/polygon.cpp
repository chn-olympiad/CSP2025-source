#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[5005],s,ctz;
int ct(int x,int y,int h)
{
	if(h==n) return x;
	else return ct(x*2+y,h*(h+1)/2,h+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	s=ct(1,2,3);
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
