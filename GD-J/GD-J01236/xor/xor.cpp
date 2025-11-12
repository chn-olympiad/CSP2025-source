#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],mx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<(1<<n);i++)
	{
		long long t=0,s=-1,c=0;
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1)))
			{
				if(t==1) s=s^a[j];
				else t=1,s=a[j];
			}
			else t=0,s=-1;
			if(s==k) c++,t=0,s=-1;
		}
		mx=max(mx,c);
	}
	printf("%lld",mx);
	return 0;
}
