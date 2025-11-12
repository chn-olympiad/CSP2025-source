#include <bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
priority_queue<int>a,b,c;

void run(int x,int y,int z)
{
    ans += max(max(x,y),z);
    if(x > y && x > z){
        a.push(max(y,z)-x);
        if(a.size() > n/2){
            ans += a.top();
            a.pop();
        }
    }
    else if(y > z){
        b.push(max(x,z)-y);
        if(b.size() > n/2){
            ans += b.top();
            b.pop();
        }
    }
    else{
        c.push(max(x,y)-z);
        if(c.size() > n/2){
            ans += c.top();
            c.pop();
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans = 0;
        scanf("%d",&n);
        for (int i = 1;i<=n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            run(x,y,z);
        }
        while(!a.empty()) a.pop();
        while(!b.empty()) b.pop();
        while(!c.empty()) c.pop();
        printf("%lld\n",ans);
    }
    return 0;
}