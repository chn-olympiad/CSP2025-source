#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[4][N],cnt[4],ans;
bool flag1,flag2,flag3;
void dfs(int id,int sum){
    if(id==n){
        ans=max(ans,sum);
        return;
    }
    if(cnt[1]+1<=(n>>1)&&flag1){
        cnt[1]++;
        dfs(id+1,sum+a[1][id+1]);
        cnt[1]--;
    }
    if(cnt[2]+1<=(n>>1)&&flag2){
        cnt[2]++;
        dfs(id+1,sum+a[2][id+1]);
        cnt[2]--;
    }
    if(cnt[3]+1<=(n>>1)&&flag3){
        cnt[3]++;
        dfs(id+1,sum+a[3][id+1]);
        cnt[3]--;
    }
}
void solve(){
	flag1=flag2=flag3=0;
    ans=0,cnt[1]=0,cnt[2]=0,cnt[3]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
    	flag1|=(a[1][i]>0);
    	flag2|=(a[2][i]>0);
    	flag3|=(a[3][i]>0);
	}
	if(!flag1&&!flag2){
        sort(a[3]+1,a[3]+n+1);
        for(int i=n;i>(n>>1);i--) ans+=a[3][i];
	}else if(!flag1&&!flag3){
	    sort(a[2]+1,a[2]+n+1);
	    for(int i=n;i>(n>>1);i--) ans+=a[2][i];
	}else if(!flag2&&!flag3){
	    sort(a[1]+1,a[1]+n+1);
	    for(int i=n;i>(n>>1);i--) ans+=a[1][i];
	}else dfs(0,0);
    printf("%d\n",ans);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}

