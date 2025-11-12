#include <bits/stdc++.h>
using namespace std;
int a[100010][4],b[100010],maxp[100010],s[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,ans;
	scanf("%d",&t);
	while(t--){
		int n,op;
		ans=0;
		for(int i=1;i<=n;i++) b[i]=100000;
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int maxn=-1;
			for(int j=1;j<=3;j++)
				if(a[i][j]>maxn) maxn=a[i][j],maxp[i]=j;
			ans+=maxn;
			s[maxp[i]]++;
		}
		for(int i=1;i<=3;i++) if(s[i]>(n/2)) op=i;
		for(int i=1;i<=n;i++){
			if(maxp[i]!=op) continue;
			for(int j=1;j<=3;j++){
				if(j==maxp[i]) continue;
				b[i]=min(b[i],a[i][maxp[i]]-a[i][j]);
			}
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=(s[op]-(n/2));i++) ans-=b[i];
		printf("%d\n",ans);
	}
	return 0;
}

