#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,l=0;
	int a[11][11];
	int b[111];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			r=a[1][2];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			b[l]=a[i][j];
			l++;
		}
	}
	for(int i=1;i<=l;i++){
		for(int j=1;j<=l;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
	l=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[l];
			l++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i%2==0&&a[i][k]<a[i][k-1]){
					swap(a[i][k],a[i][k-1]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==r){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}