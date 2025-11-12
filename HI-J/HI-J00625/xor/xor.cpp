#include<bits/stdc++.h>
using namespace std;
int n,k,cnt = 0;
int a[100000]={},b[100000]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		int cnt1=a[i],x = i+1;
		if(i == k) cnt++;
	}
	for(int x = 1;x<=n;x++){ 
	
	}
	return 0;
}
