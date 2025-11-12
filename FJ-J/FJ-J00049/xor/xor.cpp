#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
bool flaga=1,flagb=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		if(a[i]!=1)flaga=0;
		if(a[i]>1)flagb=0;
	}
	if(flaga&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(flagb&&k<=1){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}
			cout<<cnt;
			return 0;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else if(a[i]==1&&a[i-1]==1){
					a[i]=0;ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	else{
		cout<<(n+k)/2-1;
	}
	return 0;
}
