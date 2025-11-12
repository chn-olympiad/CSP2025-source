#include<bits/stdc++.h>
using namespace std;
long long n,s,a[9999999],k,fc,q,z;
struct p{
	long long l,r;
}f[99999999];
bool cmp(p x,p y)
{
	if(x.r!=y.r)return x.r<y.r;
	else
	{
		return x.l>y.l; 
	}
}
int main(){
	freopen("xor6.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		s=a[i];
		if(s==k)
		{
			f[++fc].l=i;
			f[fc].r=i; 
		}
		for(int j=i+1;j<=n;j++)
		{
			s=s^a[j];
			if(s==k)
			{
				f[++fc].l=i;
				f[fc].r=j;
			}
		}
	}
	sort(f+1,f+fc+1,cmp);
	for(int i=1;i<=fc;i++)
	{
		
		if(f[i].l>q)
		{
			z++;
			q=f[i].r;
		}
	}
	cout<<z;
	return 0;
} 
