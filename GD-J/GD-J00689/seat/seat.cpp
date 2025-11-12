#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[114],R,dir,c=1,r=1,b[114],dr=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	R=a[1];
	sort(b+1,b+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==R){
			dir=i;
			break;
		}
	}
	for(int i=1;i<dir;i++){
		if(n==1){
			c=dir;
			r=1;
			break;
		}
		if(m==1){
			c=1;
			r=dir;
			break;
		}
		else{
			
			if(dr==1 && r+1>n){
				
				c++;
				dr*=-1;
			}
			else if(dr==-1 && r-1<1){
				
				c++;
				dr*=-1;
			}
			else r+=dr;
		}
		
	}
	cout<<c<<" "<<r;
	return 0;
}
