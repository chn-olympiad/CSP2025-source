#include <iostream>
#include <cstdio>
using namespace std;
int a[500000];
int n,k;
int f(int c,int b){
	if(c <=b){
		f(a[c]^a[c+1],b);
	}
	else{
		return c;
	}
}
int x(int c,int d,int e,int g){
	int y=f(c,d);
	if(d>e){
		return g;
	}
	else if(a[d]==k||y==k){
		x(d+1,d+2,e,g+1);
	}
	else{
		x(c,d+1,e,g);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m=0;
	int b[n];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		b[i]=x(i,i+1,n,0);
		if(b[i]>m){
			m=b[i];
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
