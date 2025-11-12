#include<bits/stdc++.h>
using namespace std;
long long n,sn=3,sum=0,num=0;
long long arr[5010];
long long cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	cin>>n;
	for(int i=1 ; i<=n ; i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n,cmp);
	if(arr[1]+arr[2]+arr[3]>arr[i]*2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
