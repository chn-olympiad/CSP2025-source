#include<bits/stdc++.h>
using namespace std;
int a[13][13],b[200];
int n,m,c=1,d;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	d=b[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(b[i]>b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				a[i][j]=b[c];
				if(a[i][j]==d){
					cout<<i<<" "<<j;
					return 0;
				}
				c++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[i][j]=b[c];
				if(a[i][j]==d){
					cout<<i<<" "<<j;
					return 0;
				}
				c++;
			}
		}
	}
	return 0;
}
