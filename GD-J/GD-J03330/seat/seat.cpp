#include<bits/stdc++.h>
using namespace std;
int a[1010],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sumn=n*m;
	for(int i=1;i<=sumn;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a,a+sumn+1);
	for(int i=sumn;i>=1;i--){
		if(a[i]==r){
			r=sumn-i+1;
			break;
		}
	}
	int h,l;
	l=r/n+1;
	h=r%n;
	if(r%n==0){
		l--;
		h=n;
	}
	if(l%2==0){
		h=n-h+1;
	}
	cout<<l<<" "<<h;
	return 0;
} 
