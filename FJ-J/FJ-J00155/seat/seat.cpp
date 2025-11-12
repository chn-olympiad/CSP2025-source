#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,a[101],q=1,c,r;
    cin>>n>>m;
    int w=n*m;
	for(int i=1;i<=w;i++){
		cin>>a[i];
	}
	int a1=a[1];
	for(int i=2;i<=w;i++){
		if(a1<a[i]){
			q++;
		}
	}
	c=q/n;
	if(q%n!=0){
		c++;
	}
	if((c-1)%2==0){
		r=q%n;
		if(r==0){
			r=n;
		}
	}else{
		r=n-(q-1)%n;	
	}
	cout<<c<<' '<<r;
	return 0;
}
