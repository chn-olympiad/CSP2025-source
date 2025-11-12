#include<bits/stdc++.h>
using namespace std;
int n,m,arr[10001],a,b,c;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	a=arr[0];
	sort(arr,arr+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(arr[i]==a){
			b=i+1;
		}
	}
	if(b%n==0){
		c=b/n;
		b=n;
	}else{
		c=b/n+1;
		b=b%n;
	}
	if(c%2==1){
		cout<<c<<' '<<b;
	}else{
		cout<<c<<' '<<n-b+1;
	}
	return 0;
}

