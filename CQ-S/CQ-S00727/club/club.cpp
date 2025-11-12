#include<bits/stdc++.h>
using namespace std;
#define MAXN 300000
struct skk{
	pair<int,int> val[4];
}a[MAXN+5];
int n,T,b[MAXN+5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++) scanf("%d",&a[i].val[j].first),a[i].val[j].second=j;
		long long ans=0;
		//cout<<ans<<endl;
		for(int i=1;i<=n;i++) sort(a[i].val+1,a[i].val+4);
		int cnt[4];
		for(int i=1;i<=3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			ans+=a[i].val[3].first;
			cnt[a[i].val[3].second]++;
		}
		int tot=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				int len=cnt[i]-n/2;
				for(int j=1;j<=n;j++) 
					if(a[j].val[3].second==i) 
						b[++tot]=a[j].val[3].first-a[j].val[2].first;
				sort(b+1,b+tot+1);
				for(int j=1;j<=len;j++) ans-=b[j];
			}
		}
		printf("%lld\n",ans);
	}
} 
