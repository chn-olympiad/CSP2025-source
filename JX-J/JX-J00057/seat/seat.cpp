#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,a[110],h=0,k,j=1,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
    for(h=1;h<n*m-1;h++){
        if(a[1]<a[1+h]){
            a[1]=a[1]+a[1+h];
            a[1+h]=a[1]-a[1+h];
            a[1]=a[1]-a[1+h];
        }
    }
	for(int u=1;k!=a[u];u++){
		j++;
	}
	r=j/n;
	c=j%r;
	if(j%n!=0) r++;
	if(r%2==0) c=n-c+1;
	else c=c+n;
	cout<<r<<" "<<c;
	return 0;
}
