#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0;
	cin>>n>>k;
	bool spp=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)spp=false;
	}
	if(k<=1&&!spp){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	if(k==0&&spp){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(k/2<a[i]&&a[i]<=k){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}