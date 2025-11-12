#include<bits/stdc++.h>
using namespace std;
int x[105];
int y[105];
int ax[105];
int bx[105];
int main(){
	int n,m,a=0,b=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n*m;i++){
		a=(i-1)/n+1;
		if(a%2==1){
			b=(i-1)%n+1;
		}else{
			b=abs(((i-1)%n)-n);
		}
		ax[i]=a,bx[i]=b;
	}
	int flag=x[1];
	sort(x,x+n*m+1);
	for(int i=1;i<=n*m;i++){
		y[i]=x[n*m-i+1];
	}
	for(int i=0;i<=n*m;i++){
		if(y[i]==flag){
			cout<<ax[i]<<" "<<bx[i];
			break;
		}
	}
	return 0;
}
