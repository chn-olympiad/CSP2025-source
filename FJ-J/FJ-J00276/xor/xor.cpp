#include<bits/stdc++.h>
using namespace std;
int a[10];int n,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	cout<<a[n]-a[1];
	return 0;
} 
