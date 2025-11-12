#include <bits/stdc++.h>
using namespace std;
const int MN=10501;
int n,m,a[MN],q,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&q);
			a[q]++;
			if(i==1&&j==1)f=q;
		}
	}int cnt=0;
	for(int i=f;i<=101;i++){
		cnt+=a[i];
	}int y1=cnt%n,y2=(cnt+n-1)/n;
	if(y1==0)y1=n;
	if(y2%2==0){
		printf("%d %d",y2,n+1-y1);
	}else printf("%d %d",y2,y1);
	return 0;
}

