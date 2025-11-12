#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int s=0,l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s++;
		}
	}
	if(k==0){
		if(s==0)cout<<n;
		else cout<<s/2;
	}
	if(k==1){
		if(s==1)cout<<1;
		else cout<<s;
	}
	return 0;
}
