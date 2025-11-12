#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=0;
	int a[101];
	cin >> n >> m; 
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n*m;i++){
	int maxx=-1,x=-1;
		for(int j=1;j<=n*m;j++){
			if(a[j]>maxx){
				maxx=max(maxx,a[j]);
				x=j;
			}
		}
		a[x]=-2;
		if(x==1) sum=i;
	}
	int h,l;
	
	if(sum%n!=0)  {
		h=sum%n;
		l=sum/n+1;
		if(l%2==0) {
			h=n+1-h; 
		}
	}
	else {
		h=n;	
		l=sum/n;
		if(l%2==0){
			h=1;
		} 
	}
	cout << l << " " << h ;
	return 0;
}  
