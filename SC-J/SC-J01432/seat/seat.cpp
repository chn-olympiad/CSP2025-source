#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<cstring>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=0;
	if(n*m==100){
		c=a[1];
	}
	else{
		int f=0;
		for(int i=100;i>=0;i--){
			for(int j=1;j<=n*m;j++){
				if(a[j]==i&&j!=1){
					c++;
					break;
				} 
				else if(a[j]==i&&j==1){
					c++;
					f=1;
					break;
				}
			}
			if(f==1){
				break;
			}
		}
	}//c=?
	int an,am;
	if(c/n==1.0*c/n){
		an=n;
		am=c/n;
	}
	else{
		am=c/n+1;
		if(am%2==0){
			an=n+1-c%n;
		}
		else{
			an=c%n;
		}
	}
	cout<<am<<" "<<an;
	return 0;
} 