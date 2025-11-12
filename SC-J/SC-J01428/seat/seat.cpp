#include<bits/stdc++.h>
using namespace std;
const int N=17;
int n,m,p[N*N],pt;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)
		scanf("%d",&p[i]);
	pt=p[1];
	sort(p+1,p+1+n*m,greater<int>());
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			if(p[(i-1)*n+j]==pt){
				if(i&1){
					printf("%d %d",i,j);
					return 0;
				}else{
					printf("%d %d",i,n-j+1);
					return 0;
				}
			}
	return 0;
}
