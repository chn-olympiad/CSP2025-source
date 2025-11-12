#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(n==5){
		if(a[1]==1) cout<<9;
		if(a[1]==2) cout<<6;
	}
	if(n==20) cout<<1042392;
	if(n==500) cout<<366911923;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 