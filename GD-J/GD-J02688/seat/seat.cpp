#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n,m,t,R,c=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n*m; i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (int i=1; i<=m; i++){
		if (i%2==1){
			for (int j=1; j<=n; j++){
				if (a[c]==R){
					cout<<i<<" "<<j;
					return 0;
				}
				c++;
			}
		}
		else {
			for (int j=n; j>=1; j--){
				if (a[c]==R){
					cout<<i<<" "<<j;
					return 0;
				}
				c++;
			}
		}
	}
	return 0;
}
