#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			c++;
			if(a[c]==r){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int k=n;k>=1;k--){
			c++;
			if(a[c]==r){
				cout<<i<<" "<<k;
				return 0;
			}
		}
	}
	return 0;
}
