#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	long long a[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long a1=a[1];
	if(a[2]>a[1]){
		int a1=a[2];
		a[2]=a[1];
		a[1]=a1;
	}
	for(int i=3;i<=n*m;i++){
		if(a[i-1]<a[i]){
			long long w=a[i];
			a[i]=a[i-1];
			a[i-1]=w;
			i-=2;
		}
	}
	int pm;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			pm=i;
		}
	}
	if(pm%n==0){
		c=pm/n;
		if(c%2==0)
			r=1;
		else
			r=n;
	}else{
		c=pm/n+1;
		if(c%2==0)
			r=c*n-pm+1;
		else
			r=pm-(c-1)*n;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
