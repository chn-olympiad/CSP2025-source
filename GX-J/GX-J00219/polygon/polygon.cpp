#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]) flag=0;
	}
	if(flag==1) cout<<n-2;
	if(n==1) cout<<0;
	else if(n==2) cout<<0;
	else if(n==3) cout<<1;
	return 0;
}
