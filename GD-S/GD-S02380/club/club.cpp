#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5,inf=1e9;
int t;
int n;
int a[MAXN][3];
int tmp[MAXN];
int mx[MAXN];
int cnt[3];
int ans;
int num;
void init(){
	for(int i=1;i<=n;i++){
		tmp[i]=inf;
	}
	for(int i=0;i<3;i++){
		cnt[i]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		ans=0;
		for(int i=1;i<=n;i++){
			int now=-1;
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>now){
					now=a[i][j];
					mx[i]=j;
				}
			}
			
			cnt[mx[i]]++;
			ans+=a[i][mx[i]];
		}
		int now=0;
		for(int i=0;i<3;i++){
			if(cnt[i]>cnt[now]){
				now=i;
			}
		}
		if(cnt[now]<=n/2){
			printf("%d\n",ans);
			continue;
		}
		num=0;
		for(int i=1;i<=n;i++){
			if(mx[i]==now){
				num++;
				for(int j=0;j<3;j++){
					if(j==now){
						continue;
					}
					tmp[num]=min(tmp[num],a[i][now]-a[i][j]);
				}
			}
		}
		sort(tmp+1,tmp+1+num);
		for(int i=1;i<=cnt[now]-n/2;i++){
			ans-=tmp[i];
		}
		printf("%d\n",ans);
	}
}
