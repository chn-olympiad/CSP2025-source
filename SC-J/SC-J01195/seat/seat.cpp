#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int b[10000];
int sum=0;
void f1(int c[1000][1000],int n,int m){
	int j=1;
	for(int w=0;w<=n*m;){
		if(j<=m){
			for(int i=1;i<=n;i++){
				c[i][j]=b[sum];
				w++;
				sum--;
			}
		}
		else{
			break;
		}
		j=j+1;
		if(j<=m){
			for(int i=n;i>=1;i--){
				c[i][j]=b[sum];
				w++;
				sum--;
			}
		}
		else{
			break;
		}
		j=j+1;
	}
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
		sum++;
		b[sum]=x;
	}
	int cnt=b[1];
	sort(b,b+sum+1);
	f1(a,n,m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(cnt==a[i][j]){
				cout<<j<<" "<<i;
			}
		}
	}

	return 0; 
} 