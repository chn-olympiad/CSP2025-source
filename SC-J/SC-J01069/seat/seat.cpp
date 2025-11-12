#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int num=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) num++;
	}
	int c=(num+n-1)/n,r=(num-1)%n+1;
	cout<<c<<" ";
	if(c%2==1) cout<<r;
	else cout<<n-r+1;
	return 0;
}