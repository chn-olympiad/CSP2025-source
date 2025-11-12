#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ma,f[500005][5],g[500005][5],l=0,ans;
long long fo(long long a,long long b)
{
	long long s=0;
	for(long long i=max(a,b),j=0;i>0;i/=2,a/=2,b/=2,j++)
	{
		int x=a%2;
		int y=b%2;
		if(x!=y) s+=pow(2,j);
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	 {  scanf("%lld",&a[i]),
	 	ma=max(ma,a[i]);
	 	a[i]=fo(a[i-1],a[i]);
	 }
	if(k>ma) 
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=l;j<i;j++)
		{
			if(fo(a[i],a[j])==k)
			{
				l=i,ans++;
				break;
			 } 
		}
	}
    cout<<ans;
	//相同为0，不同为1 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
