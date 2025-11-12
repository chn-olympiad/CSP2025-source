#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,k=0,d=0,c=0,r=0;
	int a[15][15]={};
	int b[105]={};
	cin>>n>>m;
	k=n*m;
	for(int i=0;i<k;i++){
		cin>>b[i];
	}
	d=b[0];
	sort(b,b+k);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i%2==1){
				a[i][n-1-j]=b[k-1];
				k--;
			}else{
				a[i][j]=b[k-1];
				k--;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]==d){
				c=j+1;
				r=i+1;
				break;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
