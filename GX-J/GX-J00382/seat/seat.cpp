#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return(a>b);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long m,n,mn,s,sum=0;
	cin>>m>>n;
	mn=m*n;
	long long arr[mn+1]={};
	for(int i=1;i<=mn;i++){
		cin>>arr[i];
	}
	s=arr[1];
	sort(arr,arr+mn,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2!=0){
				sum=(n*i+(n-j));
				if(arr[sum]==s){
					cout<<i<<' '<<j;
				}
			}else if(i%2==0){
				sum=(n*i+1-j);
				if(arr[sum]==s){
					cout<<i<<' '<<j;
				}
			}
			
		}
	}
	return 0;
}
