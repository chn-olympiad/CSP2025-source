#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],mx[N],mx2[N],cnt[4],tmp[N];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int ans=0,m=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);	
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				mx[i]=1;
				if(a[i][2]>=a[i][3]) mx2[i]=2;
				else mx2[i]=3;
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				mx[i]=2;
				if(a[i][1]>=a[i][3]) mx2[i]=1;
				else mx2[i]=3;				
			}
			else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
				mx[i]=3;
				if(a[i][1]>=a[i][2]) mx2[i]=1;
				else mx2[i]=2;				
			}
			cnt[mx[i]]++;
			ans+=a[i][mx[i]];
		}
		int id=0;
		if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
			printf("%d\n",ans);
			continue;
		}
		else if(cnt[1]>n/2) id=1;
		else if(cnt[2]>n/2) id=2;
		else id=3;
		for(int i=1;i<=n;i++){
			if(mx[i]==id) tmp[++m]=a[i][mx[i]]-a[i][mx2[i]];
		}
		sort(tmp+1,tmp+m+1);
		for(int i=1;i<=cnt[id]-n/2;i++) ans-=tmp[i];
		printf("%d\n",ans);
	}
	
	return 0;
} 
