#include<bits/stdc++.h>
using namespace std;
int r,n,m,c,ae,d,b=0;
void paizuo(int n,int m){
	r=d%m;
	if(r==0){
		c=d/n;
		r=m;
	}
	else{
		c=d/n+1;
		if(c%2==0){
			r=n-r+1;
		}
	}
	cout<<c<<' '<<r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int a[101][101];
	int zuo[100001];
	for(int i=0;i<100001;i++){
		zuo[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			zuo[b]=a[i][j];
			b++;
		}
		
	}
	for(int i=0;i<b-1;i++){
		for(int j=0;j<b-1;j++){
			if(zuo[i]>zuo[j]){
				swap(zuo[i],zuo[j]);
			}
		}
	}
	for(int i=0;i<=b;i++){
		if(zuo[i]==a[0][0]){
			d=i+1;
			break;
		}
	}
	paizuo(n,m);
	return 0;
}
