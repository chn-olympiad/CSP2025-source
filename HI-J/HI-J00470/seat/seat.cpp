#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[0];
	int s = a[0];
	for(int i = 1;i<n*m;i++){
		cin>>a[i];
	}
	int x;
	sort(a,a+n*m);
	for(int i = n*m-1;i>=0;i--){
		if(a[i]==s){
			x=n*m-i;
		}
	}
	int hang,lie;
	if(x%n!=0){
		lie = x/n+1;
	}else if(x%n==0){
		lie = x/n;
	}
	cout<<lie<<" ";
	if(lie%2==1){
		if(x==n){
			cout<<n;
			return 0;
		}
		cout<<x%n;
	}else if(lie%2==0){
		int xxx = x%n;
		xxx = n-xxx;
		cout<<xxx+1;
	}
}
