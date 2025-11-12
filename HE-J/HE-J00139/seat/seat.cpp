#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r,b[105],d=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(n<=1&&m<=1){
			a[i]=i;
			a[i]=n*m-i+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(d==1){
				c=i;
				r=j;
			}
			else if(d==2){
				c=i;
				r=j+1;
			}
			else if(d==3){
				c=i+1;
				r=j+1;
			}
			else if(d==4){
				c=i+1;
				r=j;
			}
			else d++;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
