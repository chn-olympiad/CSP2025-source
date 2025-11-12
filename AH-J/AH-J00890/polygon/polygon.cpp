#include<bits/stdc++.h>
using namespace std;
long long a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long h=0,maxx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		h+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(h>maxx*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			long long h=0,maxx=0;
			for(int j=i;j<n;j++){
				h+=a[j];
				maxx=max(maxx,a[j]);
				if(h>maxx*2&&j-i>=3){
					ans++;
					ans%=998244353;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
