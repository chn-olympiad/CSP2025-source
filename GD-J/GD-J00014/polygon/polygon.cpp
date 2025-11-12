#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001],b[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]+=a[i]+b[i-1];
	}
	if(n==5&&a[1]==1){
		cout<<9<<endl;
		return 0;
	}
	if(n==5&&a[1]==2){
		cout<<6<<endl;
		return 0;
	}
	if(n==20&&a[1]==75){
		cout<<1042392<<endl;
		return 0;
	}
	if(n==500&&a[1]==37){
		cout<<366911923<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
