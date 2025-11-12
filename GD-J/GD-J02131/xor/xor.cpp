#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2&&a[0]==a[1]){
		if(a[0]==0){
			cout<<2;
		}else{
			cout<<1;
		}
		return 0;
	}
	if(n<=2&&a[0]!=a[1]){
		if(a[0]==0||a[1]==0){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
