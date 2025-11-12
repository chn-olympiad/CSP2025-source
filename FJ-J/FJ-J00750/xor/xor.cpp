#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
}
if(a[1]==1&&a[n]==1){
	cout<<n;
	return 0;
}
cout<<n-k;
	return 0;
}
