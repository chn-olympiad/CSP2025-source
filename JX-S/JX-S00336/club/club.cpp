#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int ans;
priority_queue<int> q;
void bfs(int num){
    while(q.empty()!=1&&num!=0){
        ans+=q.top();
        q.pop();
        num--;
    }
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int num;
        ans=0;
        scanf("%lld",&num);
        for(int j=1;j<=num;j++){
                int a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
        q.push(a);
        }
        bfs(num/2);
        printf("%lld\n",ans);
    }

    return 0;
}
