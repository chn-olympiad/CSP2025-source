#include<bits/stdc++.h>
using namespace std;
long long sum[10007];
int arr[10007];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	} 
	sort(arr+1,arr+n+1);
	sum[1]=arr[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	int ans=0;
	if(n==3){
		if(arr[3]>=sum[2]){
			cout<<0;
		}
		else cout<<1;
		return 0;
	}
	return 0;
} 
