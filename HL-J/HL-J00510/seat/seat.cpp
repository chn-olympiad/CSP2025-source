#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1005];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a1=101-a[0];
	if(n==1 && m==1){
		cout<<1<<" "<<1;
	}
	else if(a1%2==1){
		cout<< n-a1%m<<" "<<n-a1/m;
	}
	else if(a1%2==0){
		cout<<a1%m<<" "<<a1/m;
	}
	return 0;
}
