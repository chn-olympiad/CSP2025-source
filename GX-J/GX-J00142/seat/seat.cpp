#include<bits/stdc++.h>
using namespace std;

int n,m;
struct op{
	int s;
	bool b;
}a[102];

bool cmp(op a,op b){
	return a.s>b.s;
}

int f(int l,int n){//l%n
	if(l%n!=0)return l%n;
	return n;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].s;
		a[i].b=(i==0);
	}
	sort(a,a+n*m,cmp);
	
	
	int l;
	for(l=0;l<n*m;l++)
		if(a[l].b==1)break;
	l++;
	
	int c,r;
	c=(l+n-1)/n;
	if(c%2==1){
		r=f(l,n);
	}else{
		r=n-f(l,n)+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
