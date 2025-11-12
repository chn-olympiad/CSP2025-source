#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
int k;
bool mark;
int a[N];
int g_sum(int p)
{
	return (1+p)*(p/2+1)/2;
}
int ou_sum(int p)
{
	return (2+p)*(p/2)/2;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) if(a[i]!=1) mark=1;
	if(mark==0)
	{
		if(n%2==1)
		{
			cout<<ou_sum(n-1);
			return 0;
		}
		else if(n%2==0)
		{
			cout<<g_sum(n-1);
			return 0;
		}
	}
	else
	{
		int cnt=0;
		int pre[N]={0};
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
		for(int i=1;i<=n;i++) if(a[i]^pre[i]==k) cnt++;
		cout<<cnt;
		return 0;
	}
	return 0;
}
