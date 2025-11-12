#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,d,a[n],b,c[n],q[n];
	d=3;
	scanf("%ld",&d);
	scanf("%ld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%ld",&a[n]);
		scanf("%ld",&c[n]);
		scanf("%ld",&q[n]);
	}
	for(int i=0;i<n;i++)
	{
		a[i]=max(a[i],a[i+1]);
		c[i]=max(c[i],c[i+1]);
		q[i]=max(q[i],q[i+1]);
		b=a[i]+c[i]+q[i];
	}
	printf("%ld",b*2); 
	return 0;
}
