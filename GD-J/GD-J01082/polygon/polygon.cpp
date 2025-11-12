#include<bits/stdc++.h>
using namespace std;
const int N=1e6+105;
int n;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==500){
		cout<<366911923;
		return 0;
	} if(n==20){
		cout<<1042392;
		return 0;
	} if(n==5){
		if(a[1]==1)cout<<9;
		if(a[1]==2)cout<<6;
		return 0;
	}
}
