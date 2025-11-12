#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	scanf("%d%d",&n,&m);
	int a[n*m];
	for(int i=0;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	int b=a[0];
	for(int i=n*m;i>1;i--){
		for(int j=1;j<i;j++){
			if(a[j]>a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			c=1+i/m;
			if(c%2==1){
				r=1+i%m; 
			}else{
				r=m-i%m;
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
