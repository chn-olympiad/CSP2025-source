#include<bits/stdc++.h>
using namespace std;
int n;
long long int k;
long long int arr[1000009];
long long int arr2[1000009];
int ans[1000009];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    
    cin>>n>>k;
    cin>>arr[0];
    arr2[0]=arr[0];
    for(int i=1;i<n;i++){
    	cin>>arr[i];
    	arr2[i]=arr2[i-1] xor arr[i];
	}
	if(arr[0]==k) ans[0]=1;
    for(int i=1;i<n;i++){
    	ans[i]=ans[i-1];
    	for(int j=i;j>0;j--){
    		if((arr2[i] xor arr2[j-1])==k){
    			ans[i]=max(ans[i],ans[j-1]+1);
    			break;
			}
		}
		if(arr2[i]==k){
			ans[i]=max(ans[i],1);
		}
	}
	cout<<ans[n-1];
	return 0;
} 
