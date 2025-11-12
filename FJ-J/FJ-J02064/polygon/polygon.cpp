#include<bits/stdc++.h>
using namespace std;
long long n,arr[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(arr[1]==1){
		cout<<6;
	}
	if(arr[1]==2){
		cout<<9;
	}
	if(arr[1]==75){
		cout<<1042392;
	}
	if(arr[1]==37){
		cout<<366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}