#include<bits/stdc++.h>
using namespace std;
long long n,a[11001],ans,js;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<(1<<n);i++){
		long long js1=0,maxm=0,sum=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<j-1)){
				js1++;
				sum+=a[j];
				maxm=max(maxm,a[j]);
			}
		}
		if(js1<3) continue;
		if(sum>2*maxm){
			ans++;
			ans%=998244353;
		}
	}
	cout<<ans;
}

