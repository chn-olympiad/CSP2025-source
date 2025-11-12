#include<bits/stdc++.h>
using namespace std;
long long n,m,a,sum=0;
long long arr[110];
long long brr[20][20];
long long cmp(long long l,long long k){
	return l>k;
}
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
cin>>n>>m;
long long l=0,k=0;
for(int i=1 ; i<=n*m ; i++){
	cin>>arr[i];
}
a=arr[1];
sort(arr+1,arr+1+n*m,cmp);
for(int i=1 ; i<=m ; i++){
	if(i%2==1){
		for(int j=1 ; j<=m ; j++){
			sum++;
			if(arr[sum]==a){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}else if(i%2==0){
		for(int j=m ; j>=1 ; j--){
			sum++;
			if(arr[sum]==a){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}
	return 0;
}
