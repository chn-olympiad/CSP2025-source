#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h=1,l=1,a[105],r;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	if(n<=1&&m<=1){
		cout<<"1"<<" "<<"1";
	} 
	sort(a+1,a+n*m+1);
	for(int j=n*m;j>=1;j--){
		cout<<"1"<<" "<<"1";
	}
	return 0;
}
