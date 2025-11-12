#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],tt,ans=1,bj[500005];
struct stu{
	int h,t;
}ss[500005];
bool cmp(stu a,stu b)
{
	if(a.h==b.h) return a.t<b.t;
	return a.h<b.h;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		long long tmp=a[i]; 
		if(a[i]==k)ss[++tt].h=i,ss[tt].t=i;
		for(int j=i+1;j<=n;j++)
		{
			tmp=tmp^a[j];
			if(tmp==k)ss[++tt].h=i,ss[tt].t=j;
		}
	}
	sort(ss+1,ss+tt+1,cmp);
	for(int i=tt;i>=1;i--)
	{
		long long sum=1;
		bj[i]=1;
		for(int j=i+1;j<=tt;j++)
			if(ss[j].h>ss[i].t)bj[i]=max(bj[i],sum+bj[j]);
		ans=max(ans,bj[i]);
	}
	printf("%lld",ans);
	return 0;
} 
