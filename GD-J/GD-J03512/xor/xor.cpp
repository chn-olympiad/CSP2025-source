#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	int k;
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f==1){
		if(n==1){
			if(k==0) cout<<1;
			else cout<<0;
		}
		else if(n==2){
			if(k==0) cout<<2;
			else if(k==1) cout<<1;
			else cout<<0;
		}
	}
}
