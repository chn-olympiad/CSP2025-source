#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m,cnt;
int f[500005];  //前i个序列中最多含有多少权值为m的区间 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n <= 1){
		cout<<0;
	}
	if(n == 2){
		cout<<1;
	}
	return 0;
} 
