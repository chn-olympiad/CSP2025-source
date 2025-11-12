#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10,inf = 1e9;
struct node{
    int a,b,c;
} a[N];
int n,cnt[5],mx[N],ans;

void dfs(int x,int now){
    if(x > n){
        ans = max(ans,now);
        return;
    }
    if(now+mx[x] <= ans){
        return;
    }
    if(cnt[1] < n/2){
        cnt[1]++;
        dfs(x+1,now+a[x].a);
        cnt[1]--;
    }
    if(cnt[2] < n/2){
        cnt[2]++;
        dfs(x+1,now+a[x].b);
        cnt[2]--;
    }
    if(cnt[3] < n/2){
        cnt[3]++;
        dfs(x+1,now+a[x].c);
        cnt[3]--;
    }
}
void sol(){
    ans = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
    }
    for(int i = n;i >= 1;i--){
        mx[i] = mx[i+1]+max({a[i].a,a[i].b,a[i].c});
    }
    dfs(1,0);
    printf("%d\n",ans);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        sol();
    }
    return 0;
}
