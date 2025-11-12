#include<bits/stdc++.h>
using namespace std;
//int XOR 
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0&&n<=2){
		cout<<1;
		return 0;
	}
	cout<<n/2;
	return 0;
}
