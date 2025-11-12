#include<bits/stdc++.h>
using namespace std;
int a,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a&1)sum++;
	}
	cout<<sum;
	if(k==1)cout<<sum;
	else cout<<n-sum;
	return 0;
}
