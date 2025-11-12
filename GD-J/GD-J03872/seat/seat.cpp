#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[105],c,r,xr,rw;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	xr=a[1];
	int i=0;
	for(int i=1;i<n*m;i++){
		bool b=1;
		for(int j=i;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				b=0;
			}
		}
		if(b){
			break;
		}
	}
	while(a[i]!=xr){
		i++;
	}
	c=(i-1)/n+1;
	int l=(c-1)*n;
	if(c%2==1){
		r=i-l;
	}
	else{
		r=n+1-(i-l);
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
