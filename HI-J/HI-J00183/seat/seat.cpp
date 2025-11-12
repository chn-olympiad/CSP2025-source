#include<bits/stdc++.h>
using namespace std;
int n, m,z;
int r,v;
int a[101],b[11][11];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	z=n*m;
	for(int i=0;i<z;i++){
		scanf("%d",a+i);
	}
	r = a[0];
	sort(a,a+z,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i*n+j]==r){
				cout<<i+1<<' ';
				if(i%2==1){
					cout<<m-j;
				}
				else{
					cout<<j+1;
				}
				break;
			}
		}
	}
	return 0;
}

