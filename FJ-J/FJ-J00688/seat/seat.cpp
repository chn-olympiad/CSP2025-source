#include<bits/stdc++.h>
using namespace std;
int main(){
frepen("seat.in","r",stdin);
frepen("seat.out","w",stdout);
	int m,n,c,d,z,t=1,g,p,r,e,k=1;
	cin>>m>>n;
	r=m+10;
	e=n+10;
	int a[r][e];
	int b[r*e];
	int f[r*e];
	cin>>c;
	d=c;
	z=2;
	for(int i=1;i<=m;i++){
		if(i%2==1){
		for(int j=z;j<=n;j++){
			cin>>a[i][j];
		}
		}else{
		for(int j=n;j>=1;j--){
			cin>>a[i][j];
		}
		}
	}
	a[1][1]=c;
	z=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
		for(int j=z;j<=n;j++){
			b[t]=a[i][j];
			t++;
		}
		}else{
		for(int j=n;j>=1;j--){
			b[t]=a[i][j];
			t++;
		}
		}
	}
	for(int i=t;i>=1;i--){
		for(int j=1;j<=i-1;j++){
			if(b[i]<b[i-j]){
			g=b[i];
			b[i]=b[i-j];
			b[i-j]=g;
			}
		}
		f[k]=b[i];
		k++;
	}
	for(int i=1;i<=k;i++){
		if(f[i]==c){
			p=i;
		}
	}
	if(p<=n){
		cout<<1<<" "<<p;
	}else{
		if(p%n==0){
			if(p/n%2==0){
				cout<<p/n<<" "<<1;
			}else{
				cout<<p/n+1<<" "<<n;
			}
		}else{
			if(p/n%2==1){
			
			cout<<ceil(p*1.0/n)<<" "<<n+1-p%n;
		}else{
			cout<<ceil(p*1.0/n)<<" "<<p%n;
		}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
