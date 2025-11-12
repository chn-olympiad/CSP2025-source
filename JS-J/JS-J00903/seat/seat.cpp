#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n*m]={};
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	int r=arr[0],s=0;
	sort(arr,arr+n*m);
	for(int i=0;i<n*m;i++){
		if(arr[i]==r)
			s=n*m-i;
	}
	int c=s/n,d=s%n;
	if(c%2==0){
		if(d==0)
			cout<<c<<' '<<1;
		else
			cout<<c+1<<' '<<d;
	}else{
		if(d==0)
			cout<<c<<' '<<n;
		else
			cout<<c+1<<' '<<n-d+1;
	}
	return 0;
}
