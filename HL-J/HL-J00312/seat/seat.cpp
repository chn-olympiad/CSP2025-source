#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],R,pm,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	cin>>a[1];
	R=a[1];
	for(int i=2;i<=x;i++){
		cin>>a[i];
	}
	sort(a+1,a+x+1,greater<int>());
	for(int i=1;i<=x;i++){
		if(a[i]==R){
			pm=i;
			break;
		}
	}
	if(pm%n==0) c=pm/n;
	else c=pm/n+1;
	if(pm%n!=0){
		if(c%2==0) r=n-pm%n+1;
		else r=pm%n;
	}
	else{
		if(c%2==0) r=1;
		else r=n;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
/*
2 2
99 100 97 98


2 2
98 99 100 97


3 3
94 95 96 97 98 99 100 93 92
*/
