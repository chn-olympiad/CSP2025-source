#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int a[N];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			R=i;
			break;
		}
	}
	int r,c;
	if(R%(m*2)<=m){
		r=R%(m*2);
	}
	else if(R%(m*2)==0){
		r=1;
	}
	else{
		r=n-(R%(m*2)-m)+1;
	}
	if(R%m!=0){
		c=R/m+1;
	}
	else{
		c=R/m;
	}
	cout<<c<<' '<<r;
	return 0;
}