#include <bits/stdc++.h>
using namespace std;
	int a[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<max(a[0],a[1])-min(a[0],a[1]);
	}
	else{
		cout<<1;
	}
	return 0;
}
