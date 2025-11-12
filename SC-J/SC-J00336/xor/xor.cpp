#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
map<long long,long long>mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i]; 
	}
	long long ans=0;mp[0]=1;
	for(long long i=1;i<=n;i++){
		a[i]=a[i]^a[i-1];
		long long temp=a[i]^k;
		if(mp[temp]){
			mp.clear();
			mp[0]=1;
			a[i]=0;
			ans++;
//			cout<<i;
		}
		else{
			mp[a[i]]=1;
		}
	}
	cout<<ans;
	return 0;
} 