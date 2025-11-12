#include<stdio.h>
#include<algorithm>
int n,m;
struct node{
	int g;
	int id;
	friend bool operator<(node n1,node n2){
		return n1.g>n2.g;
	}
}a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].g);
		a[i].id=i;
	}
	std::sort(a+1,a+1+n*m);
	int r=1,c=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			printf("%d %d",c,r);
			return 0;
		}
		if(c&1){
			if(r==n)c++;
			else r++;
		}else{
			if(r==1)c++;
			else r--;
		}
	}
	return 0;
}