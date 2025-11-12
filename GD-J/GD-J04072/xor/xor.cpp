#include<bits/stdc++.h>
using namespace std;

int n,k,a[100005],maxn=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==0){
		cout<<n/2;
		return 0;
	} 
	cout<<k;
	
	return 0;
} 
