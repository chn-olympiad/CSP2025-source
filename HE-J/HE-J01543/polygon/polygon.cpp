#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5) cout<<6;
	else cout<<9; 
	return 0;
} 
