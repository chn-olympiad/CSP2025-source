#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[500005];
int n,k;
int kol(int x,int y)
{
	int cnt=0;
	for(int i=x;i<=y;i++) cnt=a[i]^cnt;
	return cnt;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(kol(i,j)==k)
			{
				ans++;
				i=j;
			}
		}
	}
	cout<<ans;
	return 0;
}
