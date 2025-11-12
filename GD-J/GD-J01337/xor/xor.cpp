#include<cstdio>
using namespace std;
int n,r;
int a[100001];
bool find(int m,int x){
	int xo=a[x];
	for(int i=2;i<=n;i++){
		if(xo>m) return false;
		if(xo==m) return find(m,i);
		xo=xo xor a[i];
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=r;i>=1;i--){
		if(find(i,1)){
			printf("%d",i);
			return 0;
		}
	}

	return 0;
}

