#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n,sum=0,m1=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==3){
			sum+=a[i];
			m1=max(m1,a[i]);
		}
	}
	if(n==3){
		if(sum>2*m1){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	return 0;
}
