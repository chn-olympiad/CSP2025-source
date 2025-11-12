#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,a[3][N],b[N],d[N],c[N],cnt[3],tn,ans;
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int o=0;o<=2;o++)
			scanf("%d",&a[o][i]);
	cnt[0]=cnt[1]=cnt[2]=ans=0;
	for(int i=1;i<=n;i++){
		int x=max({a[0][i],a[1][i],a[2][i]});
		b[i]=0;
		if(x==a[1][i])b[i]=1;
			else if(x==a[2][i])b[i]=2;
		if(!b[i])d[i]=a[0][i]-max(a[1][i],a[2][i]);
			else if(b[i]==1)d[i]=a[1][i]-max(a[0][i],a[2][i]);
				else d[i]=a[2][i]-max(a[0][i],a[1][i]);
		cnt[b[i]]++;ans+=a[b[i]][i];
	}
}
void work(){
	if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
		printf("%d\n",ans);
		return;
	}
	int o=0;
	while(cnt[o]<=n/2)o++;
	tn=0;
	for(int i=1;i<=n;i++)if(b[i]==o)c[++tn]=d[i];
	sort(c+1,c+tn+1);
	for(int i=1;i<=cnt[o]-n/2;i++)ans-=c[i];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
}