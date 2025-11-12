#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[150];
int p[150][150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i]<=a[j]){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			
		}
	}
	return 0;
}
