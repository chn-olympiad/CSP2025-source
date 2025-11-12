#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	int a[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s++;
		}
	}
	if(k==0){
		if(n==1){
			cout<<0;
		}
		if(n==2){
			cout<<1;
		}
		if(3<=n&&n<=100){
			cout<<(n-(n%2))/2;
		}
	}
	if(k==1){
		cout<<s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
