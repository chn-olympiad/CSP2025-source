#include <bits/stdc++.h>
using namespace std;
int T,n,a[3][100005],Ans=0;;
bool bo=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
			if(a[1][i]!=0||a[2][i]!=0) bo=0;
		}
		if(bo){
			sort(a[0]+1,a[0]+n+1);
			for(int i=n;i>n/2;i--) Ans+=a[0][i];
			printf("%lld",Ans);
			return 0;
		}
	}
	return 0;
}
