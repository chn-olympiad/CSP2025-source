#include <bits/stdc++.h>
using namespace std;
int a[500001],p[500001],t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]+a[i];
	}
	if(p[n]==n){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		cout<<p[n];
		return 0;
	}
	if(k==0){
		t=n-p[n];
		for(int i=2;i<=n;i++){
			if(a[i]==1&&a[i-1]==1){
				t++;
			}
		}
		cout<<t;
	}
	return 0;
}
