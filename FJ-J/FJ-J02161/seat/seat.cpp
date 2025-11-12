#include<bits/stdc++.h>

using namespace std;
int n,m;
struct node{
	int sum,id;
}a[110];
bool cmp(node x,node y){
	return x.sum>y.sum;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sum;
		a[i].id=i;
	}
	int num=a[1].sum,x=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i].sum==num){
			x=i;
			break;
		}
	}
	int c=1,r=1;
	bool f=true;

	for(int i=1;i<x;i++){
		if(f==true) r++;
		if(f==false) r--;
		if(r>n){
			r--;
			c++;
			f=false;
		}
		if(r<1) {
			r++;
			c++;
			f=true;
		}
		
	}
	cout<<c<<' '<<r;
}
