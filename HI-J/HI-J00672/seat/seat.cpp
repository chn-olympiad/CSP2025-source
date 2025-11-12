#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],c1=0; 
struct u{
	int sc;
	int f;
}c[225];
int cmp(u aa,u bb){
	return aa.sc>bb.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i].sc;
		c[i].f=0;
	}
	c[1].f=1;
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				c1++;
				a[j][i]=c[c1].f;
				if(c[c1].f==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				c1++;
				a[j][i]=c[c1].f;
				if(c[c1].f==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
