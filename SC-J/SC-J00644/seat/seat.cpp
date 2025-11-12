#include<bits/stdc++.h>
using namespace std;
int main(){
	long long  n,m,s,x=0,l=0;
	cin>>n>>m;
	long long  q=n*m,c=0;
	long long a[q],d[q];
	long long b[n][m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	long long r=a[0];
	for(int i=0;i<q;i++){
		for(int j=0;j<q;j++){
			if(a[j]>a[j+1]){
				s=a[j];
				a[j]=a[j+1];
				a[j+1]=s;
			}
		}
	}
	for(int i=0;i<q;i++){
		d[i]=a[q-1-i];
	}
	for(int y=0;y<m;y++){
		for(int i=0;i<n;i++){
			if(l==1) b[x+1][y]=d[c];
			else b[x][y]=d[c];
			c++;
			if(y%2==0&&(x+1)%n!=0) x++;
			else if(y%2!=0&&(x+1)%n!=0&&l==0) x--;
			else if(l==1) l=0;
			else if((x+1)%n==0){
				l=1;
				x--;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==r){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
}