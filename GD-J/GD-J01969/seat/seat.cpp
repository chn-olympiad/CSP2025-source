#include<bits/stdc++.h>
using namespace std;
int a[1012],b[110][110];
bool cmp(int &a,int &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+h+1,cmp);
	b[1][1]=a[1];
	int j=2,l=1;
	while(j<=h){
		for(int i=2;i<=n;i++){
			b[i][l]=a[j];
			j++;
		}
		l++;
		b[n][l]=a[j];
		j++;
		for(int i=n-1;i>=1;i--){
			b[i][l]=a[j];
			j++;
		}
		l++;
		b[1][l]=a[j];
		j++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t==b[i][j]){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
} 
