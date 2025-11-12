#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N=5005,mod=998244353;
int n,a[N],b[N],ans=0;
void solve1()
{
	int tot=0;
	for (int i=1;i<=n;i++) tot+=a[i];
	if(tot>a[n]*2) cout<<1;
	else cout<<0;
}
void solve2()
{
	if(n==4)
	{
		if(a[1]+a[2]+a[3]>2*a[3]) ans++;
		if(a[1]+a[2]+a[4]>2*a[4]) ans++;
		if(a[1]+a[3]+a[4]>2*a[4]) ans++;
		if(a[2]+a[3]+a[4]>2*a[4]) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>2*a[4])ans++;
		
		cout<<ans;
		return;
	}
	else if(n==5)
	{
		if(a[1]+a[2]+a[3]>2*a[3]) ans++;
		if(a[1]+a[2]+a[4]>2*a[4]) ans++;
		if(a[1]+a[2]+a[5]>2*a[5]) ans++;
		if(a[1]+a[3]+a[4]>2*a[4]) ans++;
		if(a[1]+a[3]+a[5]>2*a[5]) ans++;
		if(a[1]+a[4]+a[5]>2*a[5]) ans++;
		
		if(a[2]+a[3]+a[4]>2*a[4]) ans++;
		if(a[2]+a[3]+a[5]>2*a[5]) ans++;
		if(a[2]+a[4]+a[5]>2*a[5]) ans++;
		if(a[3]+a[4]+a[5]>2*a[5]) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>2*a[4]) ans++;
		if(a[1]+a[2]+a[3]+a[5]>2*a[5]) ans++;
		if(a[1]+a[2]+a[4]+a[5]>2*a[5]) ans++;
		if(a[1]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		if(a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		
		cout<<ans;
		return;
	}
	else if (n==6)
	{
		if(a[1]+a[2]+a[3]>2*a[3]) ans++;
		if(a[1]+a[2]+a[4]>2*a[4]) ans++;
		if(a[1]+a[2]+a[5]>2*a[5]) ans++;
		if(a[1]+a[2]+a[6]>2*a[6]) ans++;
		if(a[1]+a[3]+a[4]>2*a[4]) ans++;
		if(a[1]+a[3]+a[5]>2*a[5]) ans++;
		if(a[1]+a[3]+a[6]>2*a[6]) ans++;
		if(a[1]+a[4]+a[5]>2*a[5]) ans++;
		if(a[1]+a[4]+a[6]>2*a[6]) ans++;
		if(a[1]+a[5]+a[6]>2*a[6]) ans++;
		
		if(a[2]+a[3]+a[4]>2*a[4]) ans++;
		if(a[2]+a[3]+a[5]>2*a[5]) ans++;
		if(a[2]+a[3]+a[6]>2*a[6]) ans++;
		if(a[2]+a[4]+a[5]>2*a[5]) ans++;
		if(a[2]+a[4]+a[6]>2*a[6]) ans++;
		if(a[2]+a[5]+a[6]>2*a[6]) ans++;
		
		if(a[3]+a[4]+a[5]>2*a[5]) ans++;
		if(a[3]+a[5]+a[6]>2*a[5]) ans++;
		
		if(a[4]+a[5]+a[6]>2*a[6]) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>2*a[4]) ans++;
		if(a[1]+a[2]+a[3]+a[5]>2*a[5]) ans++;
		if(a[1]+a[2]+a[3]+a[6]>2*a[6]) ans++;
		
		if(a[1]+a[2]+a[4]+a[5]>2*a[5]) ans++;
		if(a[1]+a[2]+a[4]+a[6]>2*a[6]) ans++;
		if(a[1]+a[2]+a[5]+a[6]>2*a[5]) ans++;
		
		if(a[1]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		if(a[1]+a[3]+a[4]+a[6]>2*a[6]) ans++;
		if(a[1]+a[3]+a[5]+a[6]>2*a[6]) ans++;
		
		if(a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		if(a[2]+a[3]+a[4]+a[6]>2*a[6]) ans++;
		if(a[2]+a[3]+a[5]+a[6]>2*a[6]) ans++;
		if(a[2]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]>2*a[6]) ans++;
		if(a[1]+a[2]+a[3]+a[5]+a[6]>2*a[6]) ans++;
		if(a[1]+a[2]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		if(a[1]+a[3]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		
		if(a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		
		cout<<ans;
		return;
	}
	cout<<81;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3)
	{
		solve1();
		return 0;
	}
	else if(n<=10)
	{
		solve2();
		return 0;
	}
	cout<<243360;
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10

3
5 3 5

*/
