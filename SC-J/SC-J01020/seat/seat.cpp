#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
int n=0, m=0, a[10001], t=0, s=0, c=0, r=0;	
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n*m;i++){
		a[i]=0;
	}	
	for(int i=1;i<=n*m;i++){
		scanf("%d", &a[i]);
	}
	t=a[1];
	for(int i=1;i<=m*n;i++){
		for(int j=i+1;j<=m*n;j++){
			if(a[i]<a[j]){
				int k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			s=i;
			break;
		}
	}
	if(s%n==0){
		c=s/n;
	} else{
		c=s/n+1;
	}
	if(c%2!=0){
		r=s%n;
		if(r==0){
			r=n;
		}
	} else{
		r=n-s%n+1;
		if(s%n==0){
			r=1;
		}
	}
	printf("%d %d", c, r);
	return 0;
} 