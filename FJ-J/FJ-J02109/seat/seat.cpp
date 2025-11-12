#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
int a[105];
int cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=n*m;
	for(int i=1;i<=l;i++) scanf("%d",a+i);
	int id=a[1];
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++) if(a[i]==id){id=i;break;}
	int ans1=id/n,ans2;
	if(id-id/n*n>0) ans1++;
	if(ans1&1){
		ans2=id%n;
		if(ans2==0) ans2=n;
	}else{
		ans2=n-id%n+1;
		if(ans2==n+1) ans2=1;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}

