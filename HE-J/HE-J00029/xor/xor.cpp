#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10000];
	cin>>n>>k;
	cin>>a[n];
	for(int i=1;i<=n;i++){
		if(a[i]>k){
		cout<<i;
		}
	}
	cout<<a[n];
	freclose(stdin);
	freclose(stdout);
	return 0;
}
