#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	for(int i=1;i<=m*n;i++){
		for(int k=i;k<=m*n;k++){
			if(a[i]<a[k]){
				swap(a[i],a[k]);
			}
		}
	}
	int y=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[y]==x){
					cout<<i<<" "<<j;
					return 0;
				}
				y++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[y]==x){
					cout<<i<<" "<<j;
					return 0;
				}
				y++;
			}
		}
	}
	return 0;
}


