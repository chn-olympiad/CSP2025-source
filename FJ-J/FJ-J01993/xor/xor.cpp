#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n,k;
	cin>>n>>k;
	long long ans=0,x;
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		if(x==k) ans++;
	}
	cout<<ans;
	return 0; 
}
