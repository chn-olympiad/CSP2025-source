#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],z=0;
	scanf("%d%d",&n,&m);
//	cin>>n>>m;
	for(int i=0;i<n*m;i++){
//		scanf("%d",&a[i]);
		cin>>a[i];
	}
	int x=a[z];
	for(int j=0;j<n*m;j++){
		for(int l=0;l<n*m-1;l++){
			if(a[l]<a[l+1]){
				int y=a[l];
				a[l]=a[l+1];
				a[l+1]=x;
			}
			if(a[z]!=x){
				z++; 
			}
		}
	}
	z++;
	int c=(z-1)/n+1,r;
	if(c%2==1){
		r=z%n;
		if(r==0) r=n;
	}
	if(c%2==0){
		r=n-(z%(n+1));
	}
	printf("%d %d ",c,r);
//	cout<<z;
	return 0;
}
