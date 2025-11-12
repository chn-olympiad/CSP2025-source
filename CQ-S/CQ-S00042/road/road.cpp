#include <bits/stdc++.h>
using namespace std;
namespace yhy{
    const int MAXN=2e5+5;
    const int MAXM=1e6+5;
    #define int long long
    int n,m;
    int k;
    int len[15][MAXN];
    int cost[MAXN];
    struct edge{
        int x,y,val;
    }Side[MAXM],Side_new[MAXN],Side_now[MAXN];
    /*
    原图中开 1e6 个，新图中就可以只开 1e5 个了
    */
    int tot_Side;
    bool cmp(edge A,edge B) {
        return A.val<B.val;
    }
    int fa[MAXN];
    int GF(int x) {
        if(fa[x]==x)return x;
        return fa[x]=GF(fa[x]);
    }
	int main() {
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		std::ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) {
            fa[i]=i;
        }
        for(int i=1;i<=m;i++) {
            cin>>Side[i].x>>Side[i].y>>Side[i].val;
        }
        for(int i=1;i<=k;i++) {
            cin>>cost[i];
            for(int j=1;j<=n;j++) {
                cin>>len[i][j];
            }
        }
        sort(Side+1,Side+1+m,cmp);
        int ans=0;
        for(int i=1;i<=m;i++) {
            int x=Side[i].x;
            int y=Side[i].y;
            x=GF(x),y=GF(y);
            if(x==y) continue;
            ans+=Side[i].val;
            fa[y]=x;
            Side_new[++tot_Side]=Side[i];
            if(tot_Side==n-1) break;
        }
        // cout<<"ans:"<<ans<<'\n';
        for(int i=1;i<(1<<k);i++) {
            for(int j=1;j<=n+k;j++) {
                fa[j]=j;
            }
            tot_Side=n-1;
            for(int j=1;j<n;j++) {
                Side_now[j]=Side_new[j];
            }
            int now=0;
            int cnt_now=n-1;
            for(int j=1;j<=k;j++) {
                if((i>>(j-1))&1) {
                    now+=cost[j];
                    cnt_now++;
                    for(int p=1;p<=n;p++) {
                        Side_now[++tot_Side]={n+j,p,len[j][p]};
                    }
                }
            }
            // cout<<"i:"<<i<<" now:"<<now<<" cnt_now:"<<cnt_now<<'\n';
            sort(Side_now+1,Side_now+1+tot_Side,cmp);
            for(int j=1;j<=tot_Side;j++) {
                int x=Side_now[j].x;
                int y=Side_now[j].y;
                // cout<<"x:"<<x<<" GF(x):"<<GF(x)<<" y:"<<y<<" GF(y):"<<GF(y)<<'\n';
                // cout<<"val:"<<Side_now[j].val<<'\n';
                x=GF(x),y=GF(y);
                if(x==y) continue;
                now+=Side_now[j].val;
                fa[y]=x;
                cnt_now--;
                if(cnt_now==0) break;
            }
            ans=min(ans,now);
        }
        // cout<<"clock():"<<clock()<<'\n';
        cout<<ans<<'\n';
		return 0;
	}
}
signed main() {
	yhy::main();
	return 0;
}
/*
没我想象中那么简单

但是也不难

关键点在于

如果原图没用的

那么新图也不会用

所以是对的

O(n<<10 * log(n)) 

有点悬啊

哎我怎么记得我还学过其他的求最小生成树的算法

叫 Bruvka 是吗？

不管了。

15:14 过大样例

接下来才是挑战的开始
*/