#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int n,arr[5010],cnt;
const int mask=998244353;
const ull longmask=998244353ull;

void search(int k,int now,int sum,int last)
{
	if(now==k-1)
	{
		if(arr[last]>=sum) return;
		int L=last,R=n-1,mid,ans=-1;
		while(L<=R)
		{
			mid=L+((R-L)>>1);
			if(arr[mid]<sum)
			{
				ans=mid;
				L=mid+1;
			}
			else
			{
				R=mid-1;
			}
		}
		if(ans!=-1)
		{
			cnt+=ans-last+1;
			cnt%=mask;
		}
		return;
	}
	for(int i=last;i<n-k+now+1;i++)
	{
		search(k,now+1,sum+arr[i],i+1);
	}
	return;
}

ull A(int a,int b)
{
	ull re=1;
	for(int i=b;i>b-a;i--)
	{
		re*=i;
		re%=longmask;
	}
	return re;
}

ull C(int a,int b)
{
	return A(a,b)/A(a,a);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	bool magic=1;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]!=1) magic=0;
	}
	
	if(magic&&n>20)
	{
		ull sum__=0;
		for(int i=3;i<=n;i++)
		{
			sum__+=C(i,n);
			sum__%=longmask;
		}
		cout<<sum__;
	}
	else
	{
		sort(arr,arr+n);
		for(int i=3;i<=n;i++)
		{
			search(i,0,0,0);
		}
		cout<<cnt;
	}
	return 0;
}
