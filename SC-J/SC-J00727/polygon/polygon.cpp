#include <bits/stdc++.h>
using namespace std;
int n,a[5010],mx=-1e9,s;
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		s+=a[i];
	}
	if(n==1||n==2){
		cout<<"0";
	}
	if(n==3){
		if(s>2*mx){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}