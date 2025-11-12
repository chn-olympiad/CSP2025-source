#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	int a[10000];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int sum=a[0];
	int b[10000][10000]={0};
	sort(a,a+n*m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=a[k];
			k--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==sum){
				cout<<j<<" "<<i;
				return 0;
			}else{
				break;
			}
		}
	}
	return 0;
}
