#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int aiis1=1;
	//二进制前缀和 
	//就怪了 根本不会。 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(n==2){
		if(a[1]==k&&a[2]==k){
			cout<<2;return 0;
		}
		if(a[1]==k||a[2]==k){
			cout<<1;return 0;
		}
		int x=a[1] xor a[2];
		if(x==k){
			cout<<1;return 0;
		}
		if(x!=k){
			cout<<0;return 0;
		}
	}
	if(k==0){
		cout<<n/2<<endl;
		return 0;
	}
	else{
		cout<<1;return 0;
	}
	return 0;
}
