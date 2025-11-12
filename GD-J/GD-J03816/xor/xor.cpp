#include<bits/stdc++.h>
using namespace std;
int n,k,arr[5100000],arr_2[510000],ans,maxn,count2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out ,"w";strout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			ans=arr[i];
			if(arr[i]==k&&arr_2[i]!=1){
				count2++;
				arr_2[i]=1;
				break;
				
			}
			if(arr_2[j]!=1&&arr_2[i]!=1){
				ans=ans^arr[j];
				arr_2[j]=1;
				
				if(ans==k){
					count2++;
					break;
				}
			}		
		}
		arr_2[i]=1;
	}
	if(arr[n-1]==k&&arr_2[n-1]==0){
		count2++;
	}
	cout<<count2;
	return 0;
}

