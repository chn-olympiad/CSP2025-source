#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,c,r,h;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	h=a[0];
	for(int j=0;j<=n*m;j++){
		for(int i=0;i<n*m;i++){
			if(a[i]<a[i+1]){
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}	
		}
	}
	b=0;
	for(int i=0;i<n*m;i++){
		b++;
	}
	for(int i=0;i<b;i++){
		r++;
		if(r==n){
			c++;
			b=b-r;
			r=0;
		}
		if(a[i]==h){
			cout<<c<<r<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
