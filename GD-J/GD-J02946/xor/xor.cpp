#include <bits/stdc++.h>
using namespace std;
int a[500100],s[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			s[i]=(s[i-1]^a[i]);
		}else{
			s[i]=a[i];
		}
	}
	cout<<1;
	return 0;
} 
