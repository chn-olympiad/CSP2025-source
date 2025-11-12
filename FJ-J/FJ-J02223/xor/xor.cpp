#include<bits/stdc++.h>
using namespace std;
int arr[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i]; 
	int sum=0;
	for(int i=0;i<n-1;i++){
		if(arr[i]&&arr[i+1]==k){
			sum++;
			i++;
		}
	}
	cout<<sum;
	return 0;
}
