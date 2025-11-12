#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(a[1]>a[0]){
			swap(a[1],a[0]);
		}
		if(a[0]-a[1]==k&&a[0]!=0){
			cout<<1;
		}else if(a[0]==k&&a[1]==k) cout<<2;
		else if(a[0]==0&&a[1]==0) cout<<2;
		else cout<<0;
	}else{
		cout<<0;
	}
	return 0;
}

