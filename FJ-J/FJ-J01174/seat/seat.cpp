#include<bits/stdc++.h>
using namespace std;
int n,m,tx,ty;
int a[110];
bool cmp(int x,int y){
	if(x>y) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int x,k;
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m*n;i++) printf("%d %d\n",i,a[i]);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			k=i;
			break;
		}
	}
	if(k%m==0) tx=k/m;
	else tx=k/m+1;
	if(tx%2==0&&k%m!=0) ty=(m-k%m)+1;
	else if(tx%2==0&&k%m==0) ty=m-k%m;
	else{
		if(k%m==0) ty=m;
		else ty=k%m;
	}
	printf("%d %d",tx,ty);
	return 0;
}

