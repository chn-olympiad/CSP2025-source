#include<bits/stdc++.h>
using namespace std;
using pii=pair<long long,long long>;
long long T,n,ans,t[4];
struct stu
{
	pii one,two,three;
}sum[100005];
bool cmp(stu a,stu b)
{
	if((a.one.first-a.two.first)!=(b.one.first-b.two.first))
	    return (a.one.first-a.two.first)>(b.one.first-b.two.first);
	if((a.two.first-a.three.first)!=(b.two.first-b.three.first))
	    return (a.two.first-a.three.first)>(b.two.first-b.three.first);
	if(a.one!=b.one)
	    return a.one<b.one;
	if(a.two!=b.two)
	    return a.two<b.two;
    return a.three<b.three;	    
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
		    pii t[4];   
		    scanf("%lld %lld %lld",&t[1].first,&t[2].first,&t[3].first);
		    t[1].second=1;
		    t[2].second=2;
		    t[3].second=3;
			sort(t+1,t+4);
		    sum[i].one=t[3];
		    sum[i].two=t[2];
		    sum[i].three=t[1]; 
	    }    
	    ans=0;
	    t[1]=t[2]=t[3]=0;
	    sort(sum+1,sum+1+n,cmp);
	    for(long long i=1;i<=n;i++)
	    {
	        if(t[sum[i].one.second]<n/2)
	        {
			    ans+=sum[i].one.first;
			    t[sum[i].one.second]++;
			    continue;
		    }
			if(t[sum[i].two.second]<n/2)
	        {
			    ans+=sum[i].two.first;
			    t[sum[i].two.second]++;
			    continue;
		    }
		    if(t[sum[i].three.second]<n/2)
		    {
			    ans+=sum[i].three.first;
			    t[sum[i].three.second]++;		    	
			}
		}
		printf("%lld\n",ans);
 	}
	return 0;
} 
