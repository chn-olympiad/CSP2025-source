#include <iostream>
#include <cstdio>
using namespace std;
int n,a[10000],sum=0,maxa=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		maxa=max(maxa,a[i]);
	}
	if(n<=2) cout<<0;
	if(n==3){
		if(sum>maxa*2) cout<<1;
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
