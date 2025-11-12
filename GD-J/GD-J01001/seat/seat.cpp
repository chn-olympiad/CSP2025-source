#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[2][105];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[0][i]=i;
		scanf("%d",&a[1][i]);
	}
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<n*m;j++){
			if(a[1][j]<a[1][j+1]){
				swap(a[0][j],a[0][j+1]);
				swap(a[1][j],a[1][j+1]);
			}
		}
	}
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(m%2){
			for(int j=1;j<=n;j++){
				if(a[0][cnt]==1){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[0][cnt]==1){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
