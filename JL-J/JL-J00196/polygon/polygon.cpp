#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		m=max(m,a[i]);
	}
	if(n<=3){
		if(2*m<sum){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}
