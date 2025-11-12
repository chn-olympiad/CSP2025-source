#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int b[105];
	int n,m,k,x=1;
	cin>>n>>m>>k;
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
		if(b[i]>k) x+=1;
	}
	int c=0,r=0,q=1;
	for(int i=1;i<=m;i++){
		if(x<=i*n){
			c=i;
			if(i%2==0) q=0;
			x-=(i-1)*n;
			break;
		}
	}
	if(q==0) r=n+1-x;
	else r=x;
	cout<<c<<" "<<r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
