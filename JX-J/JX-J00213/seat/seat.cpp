#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
int n,m,x,c,r,k=1;
int a[101],b[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int z=m*n;
	for(int i=0;i<=z;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	while(k<=z){
		for(int j=100;j>=0;j--){
			for(int i=1;i<=z;i++){
				if(a[i]==j){
					b[k]=a[i];
					a[i]=-1;
					k++;
				}
			}
		}
	}
	for(int i=1;i<=z;i++){
		if(b[i]==x){
			x=i;
			break;
		}
	}
	c=x/n;
	if(n*c==x){
		if(c%2==0) r=1;
		else r=n;
	}
	else {
		int y=x-n*c;
		c++;
		if(c%2==0){
			r=n-y+1;
		}
		else r=y;
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//store👖$39👔$48👕$20👗$99👘$88👙$39👚$49
//👿
