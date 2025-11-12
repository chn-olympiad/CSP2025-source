#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,k;
int a[500005];
int num[22]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,99999999};
int ans;
int pd(int a,int b)
{
	int pro=0;
	int mx=max(a,b);
	int cnt=0;
	for(int i=0;i<=21;i++)
	{
		if(mx<num[i])
		{
			cnt=i-1;
			break;
		}
	}
	while(cnt>=0)
	{
		if(a>=num[cnt]&&b>=num[cnt])
		{
			a-=num[cnt];
			b-=num[cnt];
		}
		else if(a>=num[cnt])
		{
			pro+=num[cnt];
			a-=num[cnt];
		}
		else if(b>=num[cnt])
		{
			pro+=num[cnt];
			b-=num[cnt];
		}
		cnt--;
	}
	return pro;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int start=1;
	if(a[1]==k)
	{
		start=2;
		ans++;
	}
	for(int i=2;i<=n;i++)
	{
		int sum=a[i];
		if(a[i]==k)
		{
			start=i+1;
			ans++;
			continue;
		}
		for(int j=i-1;j>=start;j--)
		{
			sum=pd(sum,a[j]);
			if(sum==k)
			{
				start=i+1;
				ans++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}