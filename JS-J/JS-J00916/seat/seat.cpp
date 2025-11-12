#include<bits/stdc++.h>
using namespace std;
const int N=17,M=107;
int a[M];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;++i)
		scanf("%d",a+i);
	int c=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for (int i=1;i<=n*m;++i)
		if (a[i]==c){
			int x=(i-1)/n+1;
			printf("%d ",x),i-=(x-1)*n;
			if (x&1) printf("%d",i);
			else printf("%d",n-i+1);
			return 0;
		}
	return 0;
}