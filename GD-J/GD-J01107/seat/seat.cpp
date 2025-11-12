#include<bits/stdc++.h>
using namespace std;
int a[101],m,n,c,r,k,R;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=m*n;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(R==a[i]){
			for(int j=1;j<=m;j++){
				if(i>(j-1)*n && i<=j*n){
					c=j;
					if(j%2!=0){
						r=i+n-j*n;
					}if(j%2==0){
						r=1+n*j-i;
					}
				}
			}
		}
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
