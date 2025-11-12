#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,aa[4],mzz,mz;
long long ans;
struct zz{
	int a,b,c,mx,cz;
};
zz k[N];
bool cmp(zz a1,zz a2)
{
	if(a1.mx==a2.mx&&a1.mx!=mzz)
		return a1.cz<a2.cz;	
	else if(a1.mx!=mzz)
		return 0;
	else if(a2.mx!=mzz)
		return 1;
	else
	 	return a1.cz<a2.cz;	
}
int pd(int h)
{
	k[h].mx=max(k[h].a,max(k[h].b,k[h].c));
	if(k[h].mx==k[h].a)
	{
		k[h].cz=k[h].mx-max(k[h].c,k[h].b);
		k[h].mx=1;
		return 1;
	}
	else if(k[h].mx==k[h].b)
	{
		k[h].cz=k[h].mx-max(k[h].c,k[h].a);
		k[h].mx=2;
		return 2;
	}
	else
	{
		k[h].cz=k[h].mx-max(k[h].a,k[h].b);
		k[h].mx=3;
		return 3;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		aa[1]=0,aa[2]=0,aa[3]=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i+=1)
		{
			scanf("%d",&k[i].a);
			scanf("%d",&k[i].b);
			scanf("%d",&k[i].c);
			aa[pd(i)]+=1;
		}
		mz=max(aa[1],max(aa[2],aa[3]));
		if(mz==aa[1])
			mzz=1;
		else if(mz==aa[2])
			mzz=2;
		else
			mzz=3;
		for(int i=1;i<=n;i+=1)
			ans+=max(k[i].a,max(k[i].b,k[i].c));
		if(mz>(n/2))
		{
			sort(k+1,k+n+1,cmp);
			for(int i=1;i<=mz-(n/2);i+=1)
				ans-=k[i].cz;
		}
		cout<<ans<<endl;
	}
	return 0;
}