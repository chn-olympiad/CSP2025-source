#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],x;
bool qqq(int q,int w){
	return q>w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d",&a[0]);
	x=a[0];
	for(int i=1;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n*m,qqq);
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			printf("%d",(i/n)+1);
			if((i/n)%2){
				printf(" %d",n-(i%n));
			}else{
				printf(" %d",(i%n)+1);
			}
			break;
		}
	}
	return 0;
}
