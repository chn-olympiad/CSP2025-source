#include<bits/stdc++.h>
using namespace std;
long long ans;
long long a[10100];
long long cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		ans=(ans^a[i]);
		if(ans==k){
			cnt++;
			ans=0;
		}
	}
	cout<<cnt;
	return 0;
}
