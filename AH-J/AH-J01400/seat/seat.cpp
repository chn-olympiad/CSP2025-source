#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,p,c,r;
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
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			p=i;
			break;
		}
	}
	if(p%n==0)c=p/n;
	else c=p/n+1;
	if(c%2==1)r=p%n!=0?p%n:n;
	else r=n-p%n+1!=0?n-p%n+1:1;
	cout<<c<<" "<<r;
	return 0;
}
