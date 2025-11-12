#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,K=1<<30;
int n,k;
int a[N],p[N];
void solve1()
{
	long long cnt=0;
	for(int i=1; i<=n; i++) p[i]=(i==1? a[i]:(p[i-1]^a[i]));//xor
	int l=0,r=0; 
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if(((p[i]^p[j-1])==k || j==1 && p[i]==k || i==j && a[i]==k) && (i<l || j>r))
			{
				cnt++;
				l=j,r=i;
			}
		}
	}
	printf("%lld",cnt);
	return;
}
void solve2()
{
	if(k==0)
	{
		long long cnt1=0,cnt_=0,cnt0=0;
		string inRange="Begin";
		for(int i=1; i<=n; i++)
		{
			if(inRange=="Begin")
			{
				if(a[i]==0) cnt_++,cnt0++;
				else inRange="One";
				continue;
			}
			if(a[i]==1)
			{
				if(inRange=="One" && a[i]!=1) inRange="Yes";
				else cnt1++;
			}
			else
			{
				if(inRange=="Yes") cnt_++;
				cnt0++;
			}
		}
		printf("%lld",(long long)max(cnt1/2+cnt_,cnt0));
	}
	else
	{
		long long cnt=0;
		for(int i=1; i<=n; i++) cnt+=a[i];
		printf("%lld",cnt);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k); 
	bool isAll01=false;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		isAll01=(a[i]!=0 && a[i]!=1? false:isAll01);
	}
	if(isAll01==true) solve2();
	else solve1();
	return 0;
}
