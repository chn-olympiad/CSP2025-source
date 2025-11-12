#include<bits/stdc++.h>
using namespace std;
int b[11][11];
int c[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
			cin>>a[i];
		}
	int x=a[0]; 
	sort(a,a+n*m);
	int j1=0;
	for(int i=0;i<n*m;i++){
			b[j1][i-j1*m]=a[i];
			if((i+1)%m==0){
				j1++;
			}
		}
	int f_x=n-1;
	int f_y=m-1;
	bool flag;
	for(int i=0;i<n;i++){
		int j=0,sum=0;
		if(f_y%2==0)f_x=n-1,flag=1;
		if(f_y%2==1)f_x=0,flag=0;
		for(j=0;j<m;j++){
			sum++;
			c[f_x][f_y]=b[i][j];
			if(flag)f_x--;
			else f_x++;
			if(sum==m){
				sum=0;
				f_y--;
				if(flag){
					flag=0;
					f_x=0;
				}
				else {
				flag=1;
				f_x=n-1;
			}
			}
	}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
				if(c[i][j]==x)cout<<j+1<<" "<<i+1;
		}
	}
	return 0;
}
