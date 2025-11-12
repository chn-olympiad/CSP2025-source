#include<bits/stdc++.h>
using namespace std;
long long n,a[10001],b[10001],vis[10001],cnt,i=1,c,d[100001];
void aaa(int cur)
{
	if(cur>3)
	{
		long long s=0,maxn=-111;
		for(int i=1;i<cur;i++)
		{
			s=s+b[i];
			maxn=max(maxn,b[i]);
		}
		if(s>maxn*2)
		{
			d[cur-1]++;
			cnt++;
		}
	}
	if(cur>n)
	{
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			b[++c]=a[i];
			cur++;
			aaa(cur);
			cur--;
			c--;
			vis[i]=0;
		}
	}
	
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	aaa(1);
	long long q=6;
	if(d[3])
	{
		cnt=(cnt+d[3]/q)%998244353;
	}
	for(int i=4;i<=n;i++)
	{
		if(d[i])
		{
			q=q*i;
			cnt=(cnt+d[i]/q)%998244353;
		}
	}
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
谁能告诉我怎么优化啊！
QaQ
* 
*/
