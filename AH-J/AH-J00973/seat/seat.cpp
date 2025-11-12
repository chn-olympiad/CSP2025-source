#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		++cnt;
		if(a[i]==x)break;
	}
	int h=cnt/n,g=cnt%n;
	if(g==0){
		if(h%2==1){
			printf("%d %d\n",h,n);
		}
		else{
			printf("%d %d\n",h,1);
		}
	}
	else{
		++h;
		if(h%2==1){
			printf("%d %d\n",h,g);
		}
		else{
			printf("%d %d\n",h,n-g+1);
		}
	}
	return 0;
}
