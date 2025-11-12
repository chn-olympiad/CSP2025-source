#include <bits/stdc++.h>
using namespace std;
short n,arr[5005],cnt,flag;
int a[5005]={1};



int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	for(int i=4;i<=5000;i++){
		a[i]=(i-2)+a[i-1]*2;
	}
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=1) flag=1;
	}
	sort(arr+1,arr+1+n);
	if(n==3 && max(arr[1],max(arr[2],arr[3]))*2>arr[1]+arr[2]+arr[3]){
		cout<<1;
	}else if(!flag){
		cout<<a[n];
	}
	return 0;
}
