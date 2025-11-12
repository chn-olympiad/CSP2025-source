#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
