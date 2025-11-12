#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+0,a+m*n+1);
	for(int i=1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
