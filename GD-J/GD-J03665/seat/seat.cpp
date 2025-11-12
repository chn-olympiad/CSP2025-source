#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[104];
int r;
int x,y;
int b=1;

bool cmp(int q,int p){
	return q>p;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	if(a[1]==r){
		cout<<1<<" "<<1;
		return 0;
	}
	x=1;y=1;
	for(int i=2;i<=n*m;i++){
		y+=b;
		if(y>n){
			x++;y=n;b=-1;
		}
		else if(y<1){
			x++;y=1;b=1;
		}
		if(a[i]==r) break;
	}
	cout<<x<<" "<<y;
	return 0;
}
