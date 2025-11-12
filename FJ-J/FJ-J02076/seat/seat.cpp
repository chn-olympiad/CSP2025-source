#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,h=0;
	cin>>n>>m;
	int b=n*m;
	int a[b];
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	int c=a[0];
	for(int x=0;x<b-1;x++){
		for(int y=x+1;x<b;y++){
			if(a[x]<a[y]){
				a[x]=a[x]+a[y];
				a[y]=a[x]-a[y];
				a[x]=a[x]-a[y];
			}
		}
	}
	for(int z=0;z<b;z++){
		if(a[z]==c){                                   
			l=(z+1)/n+1;
			h=(z+1)%n;
			if(l%2==0){
				h=m+1-h;
			}
			cout<<l<<' '<<h;
			break;
		}
	}
	return 0;
}
