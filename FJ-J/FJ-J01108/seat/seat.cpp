#include<bits/stdc++.h>
using namespace std;
int n,m,a[120];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	} 
	int p=a[1],s=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			s=i;
			break;
		}
	}
	if(s%n==0){
		int j=s/n;
		if(j%2==0){
			printf("%d 1",j);
		}else{
			printf("%d %d",j,n);
		}
	}else{
		int g=s/n;
		int i=0,j=0;
		j=g+1;
		if(j%2==0){
			i=n-(s-n*g-1);
		}else{
			i=s-n*g;
		}
		printf("%d %d",j,i);
	}
	return 0;
}

