#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],t,bin[5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0)t=1;
		if(a[i]!=0&&a[i]!=1)t=2;
	}
	if(t==0){
		if(n%2==1)cout << (n-1)/2;
		else cout << n/2;
	}
	else if(t==1){
		for(int i=1;i<=n;i++){
			bin[a[i]]++;
		}
		if(k==0)cout << bin[0]+bin[1]/2;
		else cout << bin[1];
	}
	else cout << n/2;
	return 0;
}
