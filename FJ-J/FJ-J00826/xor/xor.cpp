#include<bits/stdc++.h>
using namespace std;
int n,x,y,a[300020],k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<n/2;
	}
	else{
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			sum++;
		}
	}
	cout<<sum;
	}
	return 0;
}
