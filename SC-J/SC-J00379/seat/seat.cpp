#include<bits/stdc++.h>
using namespace std;
long long n,m,a1;
long long a[110],s[15][15],b[110],ans,x,y,xans,yans,c;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			a1=a[i];
		}
		cin >>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		for(int j=1;j<=(n*m+1)-i;j++){
			a[i]=b[j]; 
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a1==b[i]){
			ans=i;
		}
	}
	x=ans/n;
	y=ans%n;
	xans=x+1;
	c=(x+1)*n-y;
	if(x%2==0){
		if(y!=0){
		   yans=y;
		}else if(y==0){
			yans=n;
		}
	}else if(x%2!=0){
		if(y!=0){
			yans=c;
		}else if(y==0){
			yans=1;
		}
	}
	cout <<xans<<" "<<yans;
	return 0;
}