#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct Ren{
	int num,id;
}a[105];
int seat[15][15];
bool cmp(Ren x,Ren y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].num);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int c=1;c<=m;c++){
		for(int r=1;r<=n;r++){
			//printf("%d\n",a[(c-1)*n+r].id);
			if(a[(c-1)*n+r].id==1){
				if(c%2==1)printf("%d %d",c,r);
				else printf("%d %d",c,n-r+1);
				return 0;
			}
		}
	}
	return 0;
}
