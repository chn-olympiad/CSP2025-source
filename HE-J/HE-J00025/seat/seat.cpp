#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	scanf("%d,%d",&c,&r);
	int n=c*r;
	int a[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int R=a[1],p=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]<a[j]){
				int m=0;
				m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
			if(a[i]==R){
				p=i;
			}
			else if(a[j]==R){
				p=j;
			} 
		}
	}
	int h=0,l=0;
	for(int i=c;i<=n;i+=c){
		if(p<=i && p>=i-(c-1)){
			l=i/c;
			if(l%2==0){
				int x=0;
				for(int j=i-(c-1);j<=i;j++){
					c-=x;
					if(j==p){
						h=c;
					}
					c+=x;
					x++;
				}
			}
			else{
				h=p%c;
			}
		}
	}
	printf("%d %d",l,h);
	return 0;
}
