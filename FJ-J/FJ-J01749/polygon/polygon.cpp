#include<bits/stdc++.h>
using namespace std;
int n,gh=0;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		gh = max(gh,a[i]);
	}
	if(a[0]+a[1]+a[2] > gh*2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
