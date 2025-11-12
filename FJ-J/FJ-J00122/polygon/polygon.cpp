#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,ans=0;
int b[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n],MAX=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		MAX=max(MAX,a[i]);
	}
	if(MAX==1){
		long long t=1;
		while(n--){
			t=t<<2;
			t%=mod;
		}
		cout<<t;
		return 0;
	}
	b[1]=b[2]=1;
	while(!b[n+1]){
		int o=0;
		b[o]++;
		while(b[o]==2){
			b[o]=0;
			b[++o]++;
		}
		int sum=0;
		MAX=0;
		for(int i=0;i<n;i++){
			if(b[i]){
				MAX=max(MAX,a[i]);
				sum+=a[i];
			}
		}
		if(sum>2*MAX) ans=(ans+1)%mod;
	}
	cout<<ans/2;
	return 0;
}
