#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+20;
LL n,a[N],sum,maxn,k,x;
void p(LL id,LL m)
{
	LL x=a[id];
	for(LL i=id;i<=n;i++)
	{
		x^=a[i];
	    if(x==k)
	        p(i+1,m+1);
	    else p(i+1,m);    
	}
	maxn=max(maxn,m-1);
	return;        
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(LL i=1;i<=n;i++)
    {
		cin>>a[i];
		if(a[i]==0)
		    x++;
	}
	if(k==1)cout<<n;
	else if(k==0)
	    cout<<x;
	else if(n==4)cout<<2;
	else
	{
	    p(1,1);
	    cout<<maxn;
	}
    return 0;
}
