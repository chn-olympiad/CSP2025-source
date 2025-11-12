#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		} 
	}
	if(a[n]==1){
		long long k=0,s;
		for(int i=3;i<=n;i++){
			s=1;
			for(int j=0;j<i;j++){
				s*=(n-j);
				s%=998244353;
			}
			for(int j=1;j<=i;j++){
				s/=j;
			}
			k+=s; 
		}
		cout<<k;
		return 0;
	}
	
	return 0;
}
