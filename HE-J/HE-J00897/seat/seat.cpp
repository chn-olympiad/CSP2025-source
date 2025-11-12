#include<bits/stdc++.h>
using namespace std;
int b[10000][10000];
int a[10000];
int c;
int d;
int e;
int main(){
	freopen("×ùÎ»(seat).in","r",stdin);
	freopen("×ùÎ»(seat).out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	for(int i=1;i<=n*m;i++){
		
		if(a[i]<=a[i+1]){
			c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			e=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(n%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[i];
				if(b[i][j]==a[e]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[i];
				if(b[i][j]==a[e]){
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}
		
	}
	return 0;
}
