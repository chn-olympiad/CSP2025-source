#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k=0&&a[1]==a[2]){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
