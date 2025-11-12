#include<bits/stdc++.h>
using namespace std;
int b[10][10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[1000];
	int m,n,k,s=1,r;
	cin>>n>>m;
	int c=n*m;
	if(n>10||n<0){
		return 0;
	}
	if(m>10||m<0){
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>100||a[i]<0){
			return 0;
		}
	    for(int j=1;j<=i-1;j++){
		    if(a[i]==a[j]){
				return 0;
			}
		}
	}
	r=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]>a[j+1]){
				k=a[j+1];
				a[j+1]=a[j];
				a[j]=k;
			}
		}
	}
	for(int i=1;i<m;i++){
		if(s%2==1){
			for(int j=1;j<n;j++){
				b[i][j]=a[c];
				c--;
				s++;
			}
		}
		else{
			for(int j=n;j>1;j--){
				b[i][j]=a[c];
				c--;
				s++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==r){
				cout<<i<<' '<<j;
			}
		}
	}
}