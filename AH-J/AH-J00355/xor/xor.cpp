#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[50010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c=a[0]^a[1];
	if(c==k){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
