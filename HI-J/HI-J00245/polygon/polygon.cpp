#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n<3)cout<<0;
	sort(arr+1,arr+1+n);
	if((arr[1]+arr[2])>arr[3]){
		cout<<1;
	}else{
		cout<<0;
	}
}
