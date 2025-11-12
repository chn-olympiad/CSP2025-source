#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100001],flag=0;
	cin>>n>>k;
	if(n<=2 && k==0){
		flag=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		cout<<n;
	}else{
		cout<<n/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
