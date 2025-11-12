#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r,d;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+n*m+1,cmp);
	int u;
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			u=i;
			break;
		}
	}
	c=u/n;
	if(u%n!=0){
		c++;
	}
	if(c%2==1){
		r=(u%n?u%n:n);
	}
	else{
		r=n-(u%n?u%n:n)+1;
	}
	cout<<c<<' '<<r;
	return 0;
} 
