#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm;
	int a[105],r,pm=0,c=0;
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
		r=a[1];
	}
	sort(a,a+nm+1);
	for(int i=1;i<=nm;i++){
		if(a[i]==r){
			pm=nm-i;
		}
	}
	if(pm<=n){
		cout<<"1"<<" "<<pm;
	}
	else{
		c=pm/n+1;
		if(c%2==0){
			r=n-pm%n+1;
		}
		else{
			 r=pm%n;
		}
		cout<<c<<" "<<r;
	}
	return 0;
}

