#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0,c,r=0;
	cin>>n>>m;
	int a[n*m+1],d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i];
	}
	for(int i=2;i<=d;i++){
		if(a[1]<a[i]){
			s++;
		}
	}
	c=s/m+1;
	if(m>s){
		r=m-s+1;
		cout<<c<<" "<<r;
		return 0;
	}
	if(m<s){
		r=s%m+1;
		cout<<c<<" "<<r;
		return 0;
	}
	else{
		r=s;
		cout<<c<<" "<<r;
		return 0;
	}
	return 0;
}
