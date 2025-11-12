#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans;
bool f(int l,int r){
	if(r-l+1<3)	return 0;
	long long sum=0;
	for(int i=l+1;i<=r;i++){
		sum=sum+a[i];
	}
	return sum>2*a[r];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(i,j)){
				ans++;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}