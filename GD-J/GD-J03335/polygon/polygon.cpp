#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,n,a[500500];
int get(int x)
{
	int sum=0;
	while(x)
	{
		sum++;
		x/=2;
	}
	return sum;
}
void work()
{
	int i=0;
	while(i<=(1<<(n))-1)
	{
		int sum=0,mx=-114514;
		int up=get(i);
		for(int j=1;j<=up;j++)
		if((i>>(j-1))&1) sum+=a[j+1],mx=max(mx,a[j+1]);
		if(sum>=mx*2) ans++;
		i++;
	} 
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		cout<<1;
		return 0;
	}
	work();
	cout<<ans;
}
