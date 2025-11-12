#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e6+20;
LL n,a[N],sum;
bool pd[N];
void p(LL m,LL maxn,LL he,LL x)
{
	if(m>=3)
	{
		if(he>2*maxn)
		{
		   sum++;
		   sum%=998244353;
	    }
	}
	for(LL i=x+1;i<=n;i++)
	    if(!pd[i])
	    {
	        pd[i]=true;
	        p(m+1,max(maxn,a[i]),he+a[i],i);
	        pd[i]=false;
		}
	return;        
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(LL i=1;i<=n;i++)
	    p(1,a[i],a[i],i);
	cout<<sum;
    return 0;
}
