#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],val=105;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	val=a[1];
	sort(a+1,a+n*m+1,cmp);
	int nx=1,ny=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==val){
			printf("%d %d\n",ny,nx);
			return 0;
		}
		if(ny%2){
			if(nx!=n) nx++;
			else ny++;
		}else{
			if(nx!=1) nx--;
			else ny++;
		}
	}
	return 0;
}
