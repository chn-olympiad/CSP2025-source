#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>> n >> m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1) r = a[i];
	}
	sort(a+1,a+(n*m)+1);
	int x=1,y=1,z=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			printf("%d %d",y,x);
			break;
		}
		if(x+z>n||x+z<1){
			y+=1;
			z = 0-z;
		}
		else x+=z;
	}
	return 0;
}
