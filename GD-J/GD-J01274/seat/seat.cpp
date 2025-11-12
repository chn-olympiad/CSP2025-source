#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[1000];
int a[100][100];
int c[100][100];
int num;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(i==0&&j==0){
				num=a[i][j];
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[sum]=a[i][j];
			sum++;
		}
	}
	for(int i=0;i<n*m-m;i++){
		for(int j=0;j<=n*m-m;j++){
			if(b[j]<b[j+1]){
				int s=b[j];
				b[j]=b[j+1];
				b[j+1]=s;
			}
		}
	}
	sum=0;
	int cx,cy;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				c[i][j]=b[sum];
				if(c[i][j]==num){
					cx=i;
					cy=j;
				}
				sum++;
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				c[i][j]=b[sum];
				if(c[i][j]==num){
					cx=i;
					cy=j;
				}
				sum++;
			}
		}
	}
	cout<<cx+1<<cy+1;
}
