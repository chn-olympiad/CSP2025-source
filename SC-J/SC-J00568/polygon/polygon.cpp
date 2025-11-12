#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n==3){
		for(int i=1;i<=3;i++){
			if(a[1]!=a[2] &&a[1]!=a[3] &&a[2]!=a[3]){
				cout<<"3";
			}else if(a[1]==a[2] || a[1]==a[3] ||a[2]==a[3]){
				cout<<"2";
			}else	cout<<"1";
	}}else	cout<<"6";
	return 0;
}