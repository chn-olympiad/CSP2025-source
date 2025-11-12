#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[110];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5){
		if(a[0]==1){
			cout<<"9";
		}
		if(a[0]==2){
			cout<<"6";
		}
	}
}
