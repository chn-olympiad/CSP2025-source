#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
int mod=998244353;
long long s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(n>=3){
			if(ans>2*a[i]){
				s++;
				s=s%mod;
			}
		}
	}
	cout<<s%mod<<'\n';
	return 0;
}
