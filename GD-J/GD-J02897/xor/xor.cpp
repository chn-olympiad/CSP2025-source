#include<bits/stdc++.h>
using namespace std;
long long q,k,a[12345],z[12345],qw=0;
long long qaz(long long x,long long y)
{
	
	long long u=0,t=1;
	for(long long i=x,j=y;i>0||j>0;i=i/2,j=j/2)
	{
	u+=((i%2+j%2)%2)*t;
	t=t*2;
	}
	return u;
}
long long wsx(long long x,long long y)
{
	long long u=0,t=1;
	for(long long i=x,j=y;i>0||j>0;i=i/2,j=j/2)
	{
	u+=((2+i%2-j%2)%2)*t;
	t=t*2;
	}
	return u;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>q>>k;
	z[0]=0;
	for(long long i=1;i<=q;i++)
	{
		scanf("%d",&a[i]);
		z[i]=qaz(z[i-1],a[i]);
	}
	for(long long i=0;i<q;i++)
	{
		for(long long j=i+1;j<=q;j++)
		{
			if(wsx(z[j],z[i])==k){
				qw++;
				
				i=j;
			}
		}
	}
	cout<<qw;
	return 0;
}
