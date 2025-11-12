#include<bits/stdc++.h>
using namespace std;
int n,arr[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(arr[0]+arr[1]>arr[2])cout<<1;
	else cout<<0;
	return 0;
}