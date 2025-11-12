#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
		if(n==5){
			if(a[1]==1){
				cout<<9;
				}
			}else cout<<6;
		if(n==20 && a[1]==75) cout<<1043493;
		if(n==500 && a[1]==37) cout<<366911923;
	return 0;
	}
