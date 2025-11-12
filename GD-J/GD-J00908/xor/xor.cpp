#include<bits/stdc++.h>
using namespace std;
int n,k,tmp,t2,a[1000];
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) tmp++;
		else t2++;
	}if(tmp==t2) cout<<0<<endl;
}
