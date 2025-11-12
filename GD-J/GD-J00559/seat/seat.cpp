#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int a[maxn],n,m,l,t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	l=n*m;
	for(int i=1;i<=l;i++){
		scanf("%d",&a[i]);
	} 
	t=a[1];
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	printf("%d ",(t-1)/n+1);
	if(((t-1)/n+1)&1){
		printf("%d",(t%n==0?n:t%n));
	}else{
		printf("%d",((n-(t%n)+1)==n+1?n:(n-(t%n)+1)));
	}
	return 0;
}
