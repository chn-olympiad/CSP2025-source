#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N 500010
using namespace std;
inline long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int a[N],sum[N],vis[N],d[N],lst[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	n=read();k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum[i]=sum[i-1]^a[i];
	}
	int ans=0;
	for(int len=1;len<=n;len++)
	{
		int l=1;
		while(l+len-1<=n)
		{
			int r=l+len-1;
			if((vis[r]-vis[l-1])>0){l++;continue;}
			else if((sum[r]^sum[l-1])==k){
			    ans++;
				d[l]++;d[r+1]--;
				l+=len;
				continue;
			}
			l++;
		}
		for(int i=1;i<=n;i++)
		{
			d[i]+=d[i-1];
			lst[i]+=d[i];
			vis[i]=vis[i-1]+lst[i];
			d[i]=0;
		} 
	}
	printf("%lld",ans);
	return 0;
}

