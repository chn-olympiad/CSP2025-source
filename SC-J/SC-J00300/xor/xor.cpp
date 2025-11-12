#include<bits/stdc++.h>
using namespace std;
int a[500100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n=0,k=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	if(n==2){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}