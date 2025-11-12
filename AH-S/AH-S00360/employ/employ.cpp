#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[501];
int p[501],k[501],q[501];
int n,m;
bool check()
{
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(q[i]<=c) c++;
		if(a[i]=='0') c++;
	}
	return ((n-c)>=m);
}
int ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		k[i]=i;
	}
	do{
		for(int i=1;i<=n;i++)
		{
			q[i]=p[k[i]];
		}
		ans+=check();
		ans%=998244353;
	}while(next_permutation(k+1,k+n+1));
	cout<<ans;
	return 0;
}

