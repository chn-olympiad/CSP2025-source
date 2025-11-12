#include<bits/stdc++.h>
#define LL long long
#define N 500005
using namespace std;
int n;
LL K,a[N];
bool bj[N];
int sum=0;
int flag=-1;
void dfs(int k,LL num)
{
	if(num==K)
	{
//		cout<<k<<"\n";
		sum++;
		return;
	}
	if(bj[k-1]==true&&bj[k+1]==true)
	{
		return;
	}
	bj[k]=true;
	int s=sum;
	if(bj[k+1]==false)
	{
//		cout<<111<<"\n";
		if(num!=-1) dfs(k+1,num^a[k]);
		else dfs(k+1,a[k]);
		if(s!=sum)
			return;
		if(num!=-1) dfs(k+1,a[k]);
		if(s==sum&&bj[k-1]==true)
		{
			bj[k]=false;
			return;
		}
		if(s!=sum)
			return;
	}
	if(bj[k-1]==false)
	{
		if(num!=-1) dfs(k-1,num^a[k]);
		else dfs(k-1,a[k]);
		if(s!=sum)
			return;
		if(num!=-1) dfs(k-1,num^a[k]);
		if(s==sum&&bj[k-1]==true)
		{
			bj[k]=false;
			return;
		}
		if(s!=sum)
			return;
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>K;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(K==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) sum++;
			else if(a[i]=a[i-1]) sum++;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==K)
		{
//			cout<<i<<'\n';
			bj[i]=true;
			sum++;
//			cout<<1111<<'\n';
			if(a[i-1]==K||i==1) continue; 
			dfs(i-1,-1);
			flag=i+1;
		}
	}
	if(a[n]!=K)
	{
		bj[n+1]=true;
		dfs(flag,n);
	}
	cout<<sum;
	return 0;
}