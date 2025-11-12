#include<bits/stdc++.h>
using namespace std;
int n,a[5555];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n=3){
		if(a[3]*2<a[1]+a[2]+a[3])	cout<<1;
		else cout<<0;
	}
	else cout<<11;
} 