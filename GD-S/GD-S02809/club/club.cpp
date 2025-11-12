#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int a[100005][5];
int b[100005],c[100005];
int cnt[5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);memset(cnt,0,sizeof(cnt));memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				b[i]=1;cnt[1]++;
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				b[i]=2;cnt[2]++;
			}
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
				b[i]=3;cnt[3]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				int mx=max(a[i][1],max(a[i][2],a[i][3]));
				int mn=n,id=0;
				for(int j=1;j<=3;j++){
					if(mx==a[i][j]){
						if(cnt[j]<=mn){
							mn=cnt[j];
							id=j;
						}
					}
				}
				b[i]=id;
				cnt[id]++;
			}
		}
		int id=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>(n/2)){
				id=i;
				break;
			}
		}
		int tot=0;
		if(id!=0){
			for(int i=1;i<=n;i++){
				if(b[i]==id){
					int mx=0,t=0;
					for(int j=1;j<=3;j++){
						if(id==j)continue;
						if(a[i][j]>mx){
							mx=a[i][j];
							t=j;
						}
					}
					c[++tot]=a[i][b[i]]-a[i][t];
				}
			}
		}
		int len=cnt[id]-(n/2);
		sort(c+1,c+tot+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][b[i]];
		}
		for(int i=1;i<=len;i++){
			ans-=c[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
