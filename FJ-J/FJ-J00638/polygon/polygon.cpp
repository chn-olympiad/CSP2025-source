#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+5;
int n,a[N],sum;
int cc(int k){
	int ans=1;
	for(int i=0;i<k;i++){
		ans=ans*(k-i)%998244353;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		sum+=cc(i)%998244353;
	}
	cout<<sum;
	return 0;
}
