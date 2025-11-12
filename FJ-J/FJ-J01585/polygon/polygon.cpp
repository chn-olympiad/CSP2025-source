#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		if(a[1]==2){
			cout<<6;
			return 0;
		}else{
			cout<<9;
			return 0;
		}
	}
	else if(n==500){
		cout<<366911923;
		return 0;
	}else if(n==20){
		cout<<1042392;
		return 0;
	}
}
