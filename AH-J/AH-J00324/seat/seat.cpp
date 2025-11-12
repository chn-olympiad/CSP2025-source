#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){ 
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1],id=0;
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==f){
			id=i;
			break;
		}
	}
	//cout<<id;
	int a,b;
	if (id%n!=0){
		b=id/n+1;
		//cout<<1;
	}
	else b=id/n;
	
	if (b%2==0){
		int w=id%n;
		if (w!=0){
			a=n-w+1;
		}
		else {
			a=1;
		}
	}
	else{
		int w=id%n;
		if (w!=0){
			a=w;
		}
		else {
			a=n;
		}
	} 
	cout<<b<<" "<<a;
	/*
	if (((id-1)/m+1)%2==1){
		if (id==0) cout<<0<<" "<<m;
		cout<< (id-1)/m+1<<" "<<id/(m+1);
	}
	else cout<<(id-1)/m<<" "<<id/(m+1);
	id=lower_bound(a+1,a+1+n,f)-a;
	if ((id-1)/n%2==1){
		cout<<(id-1)/m+1<<" "<<id/m;
	}
	else cout<<(id-1)/m+1<<" "<<m-(id/m);
	 */
	return 0;
}
