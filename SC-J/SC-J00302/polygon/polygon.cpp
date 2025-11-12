#include "bits/stdc++.h"
using namespace std;
int a[5010];

long long jc(int n){
	int ans=1;
	for(int i=1;i<=(1+n)*n/2;i++){
		ans*=i;
	}
	return ans;
}
int main(){
	cin.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	long long ans=0;
	for(int r=3;r<=n;r++){
		for(int l=1;l<=r-2;l++){
			int fn=a[r]-a[l];
			for(int i=l+1;i<r;i++){
				if(fn<a[i]){
					ans=ans+jc(r-i);
				}
			}
		}
	}
	cout<<(ans*3)%998244353;
	
	
	return 0;
} 