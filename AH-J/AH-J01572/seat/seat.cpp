#include "iostream"
#include "algorithm"
int n,m,x,y;
int a[105][105],b[105],s=1;
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			b[s++]=a[i][j];
		}
	}
	int r=b[1],l;
	sort(b+1,b+1+s);
	for(int i=2;i<=s;++i){
        if(b[i]==r)l=s-i+1;
	}
    y=l/n;

    if(y*n!=l)++y;
    int gs=n*(y-1);
    if(y%2==1){
        x=l-gs;
    }
    else {
        x=n*y-l+1;
    }
    printf("%d %d",y,x);
	return 0;
}
