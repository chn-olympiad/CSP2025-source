#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+3);
	if(a[2]>=(a[0]+a[1])){
		cout<<0;
	}
	else{
		cout<<1;
	}
}
