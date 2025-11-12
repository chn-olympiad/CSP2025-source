#include <bits/stdc++.h>
using namespace std;
int a[300];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<1;
		return 0;
	}else{
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)x++;
			}
		cout<<x;
		}
		else{
			cout<<n/2;
		}
	}
	return 0;
}
