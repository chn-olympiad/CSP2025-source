#include<bits/stdc++.h>
using namespace std;
int t,n,a[100003][5],m,r[5];
void f(int now,int z)
{
	if(now==n+1)
	{
		m=max(m,z);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(r[i]<n/2)
		{
			r[i]++;
			f(now+1,z+a[now][i]);
			r[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		r[1]=0,r[2]=0,r[3]=0,m=0;
		f(1,0);
		printf("%lld\n",m);
	}
	return 0;
}
