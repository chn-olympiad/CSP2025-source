#include<bits/stdc++.h>
using namespace std;
long long n,a[5500],q[5500],z;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		q[i]=a[i]+q[i-1];
	}
	for(int r=1;r<=n;++r){
		for(int l=r+2;l<=n;++l){
			long long mx=0;
			for(int i=r;i<=l;++i){
				mx=max(q[i],mx);
			}
			if(mx*2>q[l]-q[r-1]){
				++z;
			}
		}
	}
	cout<<z%998244353<<endl;
	return 0;
}
