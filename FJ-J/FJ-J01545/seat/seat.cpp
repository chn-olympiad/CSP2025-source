#include<bits/stdc++.h>
using namespace std;
int m,n,a[20][20],t,b[225];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int o=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			b[o]=a[i][j];
			o++;
		}
	}
	sort(b+1,b+1+o,cmp);
	t=a[1][1];
	int l=1,k=1;
	for(int i=1;i<=o;i++){
		a[l][k]=b[i];
		if(l%2==1){
			if(k==m){
				l++;
				k=k;
			}
			else if(k!=m){
				l=l;
				k++;
			}
		}
		else if(l%2==0){
			if(k==1){
				l++;
				k=k;
			}
			else if(k!=1){
				k--;
				l=l;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==t) cout<<i<<' '<<j;
		}
	}
	return 0;
}


