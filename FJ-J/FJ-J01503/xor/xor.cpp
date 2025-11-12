#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long ans;
int n,k,pd[N],num;
int a[N],b[N];
bool is_inc(int a,int b)
{
	for(int i=1;i<=num;i++)
	{
		if(a<=pd[i] and b>=pd[i])
			return false;
	}
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=k)b[i]=b[i-1] xor a[i];
		else{ans++;num++;pd[num]=i;}
		//printf("%d ",b[i]);
	}
	//printf("\n");
	for(int i=1;i<=n;i++)
	{
		if(b[i]<k)continue;
		for(int j=i-1;j>=0;j--)
		{
			if(b[i]-b[j]==k and is_inc(j+1,i))
			{
				ans++;
				num++;
				pd[num]=i;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

