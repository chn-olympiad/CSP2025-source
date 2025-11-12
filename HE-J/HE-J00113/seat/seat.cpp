#include<bits/stdc++.h>
using namespace std;
long long n,m,d,z,x,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m]={},b[n+5]={},q[m+5]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				int s=0;
				s=a[i];
				a[i]=a[j];
				a[j]=s;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			d=i;
		}
	}
	
	
	for(int i=1;i<=n;i++){
		int j=0;
		b[i]=i;
	}
	z=n%d;
	if(z>0){
		c=b[z];
		cout<<c;
	}
	if(z==0){
		c=d/n;
		cout<<c;
	}
	
	if(c%2!=0){
		r=d-(m*(c-1));
		cout<<" "<<r;
	}
	for(int i=m;i>=1;i--){
		int j=0;
		q[j]=i;
		j++;
	}
	x=m%d;
	if(c%2==0){
		if(x>0){
			r=q[x];
			cout<<" "<<r;
		}
		if(x==0){
			r=1;
			cout<<" "<<r;
		}	
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
