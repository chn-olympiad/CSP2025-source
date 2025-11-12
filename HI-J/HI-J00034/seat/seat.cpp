#include<bits/stdc++.h>
using namespace std;
long long r,m,n,a[105],b[15][15],c=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}

	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				c++;
				b[j][i]=a[c];
			}
		}else if(i%2==0){
			for(int j=n;j>=1;j--){
				c++;
				b[j][i]=a[c];
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(b[j][i]==r){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
