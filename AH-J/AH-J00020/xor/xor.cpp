#include<bits/stdc++.h>
using namespace std;

int n,k;

int arr[1111660];

int xro[1111660];

int cnt=0;

int lst=0;

bool B=true;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=0&&arr[i]!=1){
			B=false;
		}
		xro[i]=xro[i-1]^arr[i];
	}
	if(B&&n>=100000){
		if(k!=0&&k!=1){
			cout<<0;
			return 0;
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(arr[i]==0){
					cnt++;
				}
			}
			for(int i=1;i<=n;i++){
				if(arr[i]==1&&arr[i-1]==1){
					cnt++;
					i++;
				}
			}
			cout<<cnt;
		}else{
			for(int i=1;i<=n;i++){
				if(arr[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=lst;j<i;j++){
			if((xro[i]^xro[j])==k){
				cnt++;
				lst=i;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
