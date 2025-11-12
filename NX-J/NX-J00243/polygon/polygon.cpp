#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon3.in","r",stdin);
	freopen("polygon3.out","w",stdout);
	int n;
	cin>>n;
	int arr[n+10];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	int max=0,count=0,geshu=0,record=0,record1=0;
	for(int i=n;i>=1;i--){
		record=arr[i-1];
		record1=i-1;
		for(int j=record1;j>=1;j--){
			max+=arr[j];		
			geshu++;
			if(max>arr[i]&&geshu>=2){
					count+=j+(j-2);
				max-=arr[j];
				geshu--;
			}
			if(j==1){
				max-=record;
				geshu--;
				j=record1;
				record=arr[j];
				record1--;
				max=0;
				cout<<endl;
			}
		}
	}
	cout<<count;
}
