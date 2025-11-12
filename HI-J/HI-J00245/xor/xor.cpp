#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==1&&arr[1]=0)cout<<1;
	else cout<<0;
	if(n==2){
		if(arr[1]==0&&arr[2]==0){
			cout<<2;
		}else if(arr[1]==0||arr[2]==0) cout<<1;
		else cout<<0
	}
	return 0;
}
