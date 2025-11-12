#include <bits/stdc++.h>
using namespace std;
int n,m,R,flag=1,cick=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(flag){
			flag=0;
			R=a[i];
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]>R){
			cick++;
		}
	}
	cout<<cick/n+1<<' ';
	if((cick/n+1)%2){
		cout<<cick%n+1;
	}
	else{
		cout<<n-cick%n;
	}
	return 0;
}
