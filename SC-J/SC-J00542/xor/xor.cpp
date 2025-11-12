#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
int s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==1&&k==0) {
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=(a[i]^b[i-1]); 
	}
	for(int i=1;i<=n;i++){
		if(b[i]==k){
			s++;
		}
	}
	cout<<s;
	return 0;
}
/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3

*/ 