#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct member{
	int a;
	int b;
	int c;
};
struct member m[100005];
int cl[4];
bool cmp(struct member x,struct member y){
	return x.a > y.a;
}
long long dfs(int mi){
	int cnt[4] = {0,0,0,0};
	for(int i=1;i<=3;i++){
		if(cl[i] < n/2){
			int cha = 0;
			if(i == 1){
				cha = m[mi].a;
			}
			else if(i == 2){
				cha = m[mi].b;
			}
			else{
				cha = m[mi].c;
			}
			cl[i]++;
			cnt[i] = dfs(mi+1)+cha;
			cl[i]--;
		}
	}
	return max(cnt[1],max(cnt[2],cnt[3]));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
		scanf("%d",&n);
		memset(m,0,sizeof(m));
		memset(cl,0,sizeof(cl));
		bool l = true;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&m[i].a,&m[i].b,&m[i].c);
			if(m[i].b != 0 || m[i].c != 0){
				l = false;
			}
		}
		if(l == true){
			sort(m+1,m+n+1,cmp);
			long long ans = 0;
			for(int i=1;i<=n/2;i++){
				ans += m[i].a;
			}
			printf("%lld\n",ans);
			continue;
		}
		printf("%lld\n",dfs(1));
	}
    return 0;
}
