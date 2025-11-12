#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int temp=a[1];
	for(int i=1;i<n*m;i++){
		for(int j=1;j<=n*m-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	int now=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				s[i][j]=a[now];
				now++;
			}
		}else if(j%2==0){
			for(int i=n;i>=1;i--){
				s[i][j]=a[now];
				now++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==temp){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
