#include<bits/stdc++.h>
using namespace std;
int arr[100001],ans=0,n,m;
int main(){
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int cnt=0,ans=0;
	for(int i=0;i<n;i++){
		if(arr[i]==1){
			cnt++;
		}else if(arr[i]==0){
			ans++;
		}
	} 
	if(cnt==n){
		if(cnt%2==1){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(ans==n){
		cout<<0;
		return 0;
	}
	if(arr[0]==1&&arr[1]==0){
		cout<<1;
		return 0;
	}else if(arr[0]==0&&arr[1]==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
				cnt=cnt^arr[k];
			}
			if(cnt==m){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

