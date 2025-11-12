#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
const int N=109;
int a[N];
int cnt_r=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]>a[1])++cnt_r;
	}
	x=(cnt_r+n-1)/n;
	if(x%2)y=cnt_r-(x-1)*n;
	else y=x*n-cnt_r+1;
	printf("%d %d\n",x,y);
}