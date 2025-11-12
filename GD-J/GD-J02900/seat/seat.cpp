#include<bits/stdc++.h>
using namespace std;
int n,m;
int ach,pos=1;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1 && a[i]>ach){
			pos++;
		}
		else ach=a[1];
	}
	if(pos%n!=0){
		c=pos/n+1;
		if(c%2==0){
			r=n-pos%n+1;
		}
		else{
			r=pos%n;
		}
	}
	else{
		c=pos/n;
		r=n;
	}
	cout<<c<<" "<<r;
	return 0;
}
