#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],p,zc,w,f[15][15],sum=1,c,r,k2;
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	zc=a[1];
	sort(a+1,a+p);
	for(int j=1;j<=p;j++){
		if(a[j]==zc){
			w=p-j;
			break;
		}
	}
	for(int k1=1;k1<=m;k1++){
		if(k1%2==1){
			for(k2=1;k2<=n;k2++){
				f[k1][k2]=sum;
				sum++;
				if(w==sum-1){
					c=k1;
					r=k2;
					break;
				}
			}
		}
		else{
			for(k2=n;k2>=1;k2--){
				f[k1][k2]=sum;
				sum++;
				if(w==sum-1){
					c=k1;
					r=k2;
					break;
				}
			}
		}
	}		
	cout<<c<<" "<<r;
	return 0;
}
