#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	ll a[5005];
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=j;k<n;k++){
				if(a[i]+a[j]+a[k]>=max(max(a[i],a[j]),a[k])){
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
