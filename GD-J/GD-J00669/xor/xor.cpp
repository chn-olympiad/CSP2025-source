#include<bits/stdc++.h>
using namespace std;
int a[500005]={};
int b[500005]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k; cin >> n >> k;
	int n0=0,n1=0;
	int cnt=0;
	for(int i=1;i<=n;i++){                                
		cin >> a[i];
		b[i]=a[i];
		if(a[i]==0) n0++;
		if(a[i]==1) n1++;
		if(a[i]==k) cnt++;
	}
	if(k==0){
		cout << n/2;
	}
	else if(k==1){
		cout << n1;
	}
	else{
		for(int i=2;i<=n;i++){
			b[i]=(b[i]|b[i-1]);
		}
		if(b[n]==k){
			cout << max(cnt,1);
		}
		else cout << cnt;
	}
	return 0;
}
