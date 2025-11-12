#include<bits/stdc++.h>
using namespace std;
int a[121],b[11][11],c[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	bool flag=1;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int xiaor=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		}
	}
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[i][j]=a[k];
			k++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i%2==0){
				c[i][j]=b[i][j];
			}
			else{
				c[i][m-j-1]=b[i][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(c[i][j]==xiaor){
				cout<<i+1<<' '<<j+1<<endl;
				return 0;
			}
		}
	}
	return 0;
}
