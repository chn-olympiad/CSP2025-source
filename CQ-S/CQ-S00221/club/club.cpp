#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3],id[N],cnt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,ans=0;
		scanf("%d",&n);cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for(int i=1;i<=n;i++){
			int x=max({a[i][0],a[i][1],a[i][2]});ans+=x;
			if(a[i][0]==x)id[i]=0,cnt[0]++;
			else if(a[i][1]==x)id[i]=1,cnt[1]++;
			else id[i]=2,cnt[2]++;
		}
		int ma=0;for(int i=1;i<=2;i++)if(cnt[i]>cnt[ma])ma=i;
		if(cnt[ma]>n/2){
			priority_queue<int>pq;
			for(int i=1;i<=n;i++){
				if(id[i]==ma){
					int cm=0;
					for(int j=0;j<3;j++)if(j!=ma)cm=max(cm,a[i][j]);
					pq.push(cm-a[i][ma]);
				}
			}
			for(int i=1;i<=cnt[ma]-n/2;i++)ans+=pq.top(),pq.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
