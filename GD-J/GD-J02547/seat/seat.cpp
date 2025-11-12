#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int arr[n+1][m+1];
	for(int i=0;i<n*m;i++) cin>>a[i];
	int R=a[0];
	for(int i=0;i<n*m;i++)
		for(int j=0;j<n*m;j++)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
	int s=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			arr[i][j]=a[s++];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==R){
				if(j==1) cout<<i<<" "<<j;
				else
					cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
