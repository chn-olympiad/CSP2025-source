#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z,j=1;
	vector<int>a(n*m+1);
	cin>>n>>m;
	if(n==0||m==0){
		cout<<0<<' '<<0;
		return 0;
	}
	cin>>z;
	for(int i=2;i<=m*n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>z)
		j++;
	}
	cout<<(j-1)/n+1<<' ';
	if(((j-1)/n+1)%2){
		if(j%n==0)
		cout<<n;
		else
		cout<<j%n;
	}else{
		 if(j%n==0)
		cout<<1;
		else
		cout<<n-j%n+1;
	}
	return 0;
}
