#include<bits/stdc++.h>
using namespace std;
int n,t,st[100005],cnt,ans[5],a,x1,x2; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		cnt=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",st+j,&x1,&x2);
		}
		sort(st+1,st+n+1);
		for(int j=n;j>=n/2+1;j--){
			cnt+=st[j];
		}
		ans[++a]=cnt;
	}
	for(int i=1;i<=t;i++)printf("%d\n",ans[i]);
	return 0;
}

