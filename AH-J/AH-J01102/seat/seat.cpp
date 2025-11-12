#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],c[11][11],t=1,x,e=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		x=a[1];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		b[t]=a[i];
		t++;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
		for(int j=1;j<=n;j++){
			c[j][i]=b[e];
			e++;
			if(c[j][i]==x){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		}else{
		for(int j=n;j>=1;j--){
			c[j][i]=b[e];
			e++;
			if(c[j][i]==x){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		}
	}
	return 0;
}
