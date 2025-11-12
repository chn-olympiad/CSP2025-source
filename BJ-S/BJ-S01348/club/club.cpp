#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
const int M=1e6+5;

int t,n,cnt[4],ans;
struct Node {
    int val,id;
    bool operator < (const Node &rhs) const {
        return val>rhs.val;
    }
}a[N][4];
priority_queue<int>q[4];
void solve() {
    ans=0;
    for(int i=1;i<=3;i++)while(q[i].size())q[i].pop();
    for(int i=1;i<=3;i++)cnt[i]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=3;j++)
            scanf("%d",&a[i][j].val),a[i][j].id=j;
        sort(a[i]+1,a[i]+4);
        ans+=a[i][1].val;
        cnt[a[i][1].id]++;
        q[a[i][1].id].push(a[i][2].val-a[i][1].val);
    }
    for(int i=1;i<=3;i++) if(cnt[i]>n/2) {
        while(cnt[i]>n/2) {
            ans+=q[i].top();
            q[i].pop();
            cnt[i]--;
        }
    }
    printf("%d\n",ans);
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
            solve();

    return 0;
}
