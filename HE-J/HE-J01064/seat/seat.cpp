#include<bits/stdc++.h>
using namespace std;
int m,n,a[101],b[11][11],d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	cin>>m>>n;
	int c=m*n-1;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	d=a[0];
	sort(a,a+m*n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			b[i][j]=a[c];
			c--;
			if(b[i][j]==d){
				cout<<i+1<<" "<<j+1;
				break; 
			}
		}
	}
	return 0;
} 
