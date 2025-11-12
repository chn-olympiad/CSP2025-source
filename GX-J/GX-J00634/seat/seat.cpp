#include <cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;scanf("%d%d%d",&n,&m,&r);
	int c[n*m]={0};
	for(int i=1;i<n*m && scanf("%d",&c[i]);i++){}
	c[0]=r;
	for(int i=0;i<n*m;i++){
		int w=i;
		while(c[w]>c[w-1] && w>0){
			c[w]^=c[w-1];
			c[w-1]^=c[w];
			c[w]^=c[w-1];
			w--;
		}
	}
	for(int i=0;i<n*m;i++){
		if(c[i]==r){
			r=i+1;
			break;
		}
	}
	int l=(r+n-1)/n;
	r=(n>=r ? r : r%n);
	int h=(l&1 ? r : n-r+1);
	printf("%d %d",l,h);
	return 0;
}
