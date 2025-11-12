#include<bits/stdc++.h>
using namespace std;
int a[105];
int cmp(int x,int y){
	return x>y;
}
int hzb(int n,int x){
	int f;
	if(x%n==0){
		f=x/n;
	}
	else{
		f=x/n+1;
	}
	return f;
}
int zzb(int n,int x){
	int f=hzb(n,x),c;
	if(f%2!=0){
		if(x%n==0){
			c=n;
		}
		else{
			c=x%n;
		}
	}
	else{
		if(x%n==0){
			c=1;
		}
		else{
			c=n-x%n+1;
		}
	}
	return c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			z=i;
		}
	}
	int x=hzb(n,z);
	int y=zzb(n,z);
	cout<<x<<" "<<y;
	return 0;
}
