#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	int a[n*m]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[0];
	sort(a,a+n*m,cmp);
	int x;
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			x=i;
		}
	}
	x++;
	if(x%n!=0){
		cout<<n-x/n+1;
	}else{
		cout<<n-x%n;
	}
	cout<<" ";
	if(x%2!=0){
		cout<<x%m+1;
	}else{
		cout<<x/m;
	}	
	
	
	
	
	
	
	
	return 0;
}
