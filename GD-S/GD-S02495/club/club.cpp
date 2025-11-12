#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,z,f[5],num[5],ans,k,nk,lf,ls;
struct tclub
{
	ll a[5],maxx,maxdis,secdis;
	ll secmax;
}q[100005];
bool cmp0(ll x,ll y)
{
	return x>y;
}
bool cmp(tclub x,tclub y)
{
	if(x.maxdis==y.maxdis) return x.secdis>y.secdis;
	else return x.maxdis>y.maxdis;
}
bool cmp2(tclub x,tclub y)
{
	return x.maxdis>y.maxdis;
}
void work()
{
	if(nk==1) lf=2,ls=3;
	if(nk==2) lf=1,ls=3;
	if(nk==3) lf=1,ls=2; 
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
scanf("%lld",&t);
while(t--)
{
	ans=num[1]=num[2]=num[3]=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) 
	{
		scanf("%lld %lld %lld",&f[1],&f[2],&f[3]);
		for(int ll j=1;j<=3;j++)
			q[i].a[j]=f[j];
		sort(f+1,f+4,cmp0);
		q[i].maxdis=f[1]-f[2];
		q[i].secdis=f[2]-f[3];
		for(int ll j=1;j<=3;j++)
			if(q[i].a[j]==f[1]) 
			{
				k=j;
				break;
			}
		q[i].maxx=k;	
		for(int ll j=1;j<=3;j++)
			if(q[i].a[j]==f[2]) k=j;
		q[i].secmax=k;
	}
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(num[q[i].maxx]<n/2) 
		{
			num[q[i].maxx]++;
			ans+=q[i].a[q[i].maxx];
			k=i;
		}
		else
		{
			nk=q[i].maxx;
			break;
		} 
	}
	k++;
	work();
	for(int i=k;i<=n;i++)
	{
		if(q[i].a[lf]>=q[i].a[ls]) q[i].maxx=lf;
		if(q[i].a[lf]<q[i].a[ls]) q[i].maxx=ls;		
		q[i].maxdis=abs(q[i].a[lf]-q[i].a[ls]);
	}
	sort(q+k,q+n+1,cmp2);
	for(int i=k;i<=n;i++)
		ans+=q[i].a[q[i].maxx];
	printf("%lld\n",ans);	
}
fclose(stdin);
fclose(stdout);
	return 0;
}
