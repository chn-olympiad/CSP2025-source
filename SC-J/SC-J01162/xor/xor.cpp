#include<bits/stdc++.h>
using namespace std;
struct qqq
{
	long long x;
}qq[10000000];
long long n,m,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>qq[i].x;
	}
	if(qq[1].x==m)
	{
		cnt++;
		qq[1].x=-1;
	}
	for(long long i=2;i<=n;i++)
	{
		if(qq[i].x==m)
		{
			cnt++;
			qq[i].x=-1;
			continue;
		}
		else if(qq[i].x>=0 and qq[i-1].x>=0){
			qq[i].x=(qq[i].x xor qq[i-1].x);
			if(qq[i].x==m)
			{
				cnt++;
				qq[i].x=-1;
			}
		}
	}
	cout<<cnt;
	return 0;
}