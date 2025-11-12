#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool ff=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			ff=0;
		}
	}
	if(ff=1){
		if(k==1){
			cout<<n;
		}
		else{
			cout<<n/2;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

