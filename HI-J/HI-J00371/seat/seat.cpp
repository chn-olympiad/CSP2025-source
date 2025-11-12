#include<bits/stdc++.h>
using namespace std;
int n;
int m;
bool cmp(int x, int y){
	return x>y;
}
int d=1;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long a[n*m]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	int sum=n*m;
	sort(a+1,a+sum+1,cmp);
	int c[n][m]={0};
	for(int i=1;i<=m;i++){
		if(i==1||i%2!=0){
			for(int j=1;j<=n;j++){
				c[j][i]=a[d];
				d++;
			} 
		}else if(i%2==0){
			for(int z=n;z>=1;z--){
				c[z][i]=a[d];
				d++;
			}
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==b){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	
	return 0;
}
