#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,edge=3;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(sum>a[n]*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}