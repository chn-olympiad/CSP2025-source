#include<bits/stdc++.h>
using namespace std;
int a[500005],m[5];
void solve(){
	int n,k,l=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)l=1;
		if(a[i]<2)m[a[i]]++;
	}
	if(k==0&&l==0){
		cout<<n/2;
	}
	else if(k==0){
		cout<<a[0]/2+a[1]/2;
	}
	else{
		cout<<min(a[0],m[1]);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0; 
}
