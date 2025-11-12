#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	if(a>b){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m,arr[2000]={};
	cin>>n>>m;
	long long nm=n*m;
	int nn=nm;
	while(nn--){
		cin>>arr[nn];
	}
	long long sum=0;
	int f=arr[nm-1];
	sort(arr,arr+nm,cmp);
	for(int i=0;i<nm;i++){
		if(arr[i]==f){
			break;
		}else{
			sum++;
		}
	}
	cout<<sum%m+1<<' '<<sum/n+1;
	return 0;
}
