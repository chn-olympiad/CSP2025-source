#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[105],sum,ts,r,c;
bool cmp(int x,int y)
{
	return x>y;	
} 
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
scanf("%d %d",&n,&m);
sum=n*m;
for(int i=1;i<=sum;i++)
	scanf("%d",&a[i]);
ts=a[1];	
sort(a+1,a+sum+1,cmp);
for(int i=1;i<=sum;i++)
{
	if(a[i]==ts)
	{
		c=(i-1)/n+1;
		if(i%(2*n)==0) r=1;
		else if(i%(2*n)>n) r=n-i%n+1;
		else r=i%(2*n);
		printf("%d %d",c,r);
		return 0;
	}
}
fclose(stdin);
fclose(stdout);
	return 0;
}

