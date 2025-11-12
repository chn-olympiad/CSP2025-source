#include<bits/stdc++.h>
using namespace std;
int n,m,num,xr,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	cin>>a[1];xr=a[1];
	for(int i=2;i<=num;i++){
		scanf("%d",&a[i]);
	} 
	sort(a+1,a+1+num,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(xr==a[n*(j-1)+i]){
				cout<<j<<" ";
				if(j%2==0){
					cout<<n+1-i;return 0;
				}
				cout<<i;
				return 0;
			}
		}
	}
	return 0; 
}
