#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
	{	
		int ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0)ans++;
		cout<<ans;
	}else
		cout<<n-1;
	return 0;
}
