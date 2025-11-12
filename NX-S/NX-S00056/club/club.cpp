#include<bits/stdc++.h>
using namespace std;

bool g = 1;
int t,n,p,cnt[4];
long long ans = 0;

struct people{
    int a,b,c;
    bool ok;
}s[100001];

void dfs(int f,int x,int y,int z,long long cnt){
    if (f > n){
        if (x <= p && y <= p && z <= p)
            ans = max(ans,cnt);
        return;
    }
    for (int i = 1;i <= 3;i++){
        if (i == 1){
            x++;
            cnt += s[f].a;
            dfs(f + 1,x,y,z,cnt);
            x--;
            cnt -= s[f].a;
        }
        else if (i == 2){
            y++;
            cnt += s[f].b;
            dfs(f + 1,x,y,z,cnt);
            y--;
            cnt -= s[f].b;
        }
        else{
            z++;
            cnt += s[f].c;
            dfs(f + 1,x,y,z,cnt);
            z--;
            cnt -= s[f].c;
        }
    }
}
bool cmda(people x,people y){
    return x.a > y.a;
}
bool cmdb(people x,people y){
    return x.b > y.b;
}
bool cmdc(people x,people y){
    return x.c > y.c;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for (;t--;){
        ans = 0;
        scanf("%d",&n);
        p = n / 2;
        if (n <= 30){
            for (int i = 1;i <= n;i++)
                scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            dfs(1,0,0,0,0);
            printf("%lld\n",ans);
            continue;
        }
        for (int i = 1;i <= n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            if (s[i].b != 0 || s[i].c != 0)
                g = 0;
            s[i].ok = 0;
        }
        if (g){
            sort(s + 1,s + n + 1,cmda);
            for (int i = 1;i <= p;i++)
                ans += s[i].a;
            printf("%lld\n",ans);
            return 0;
        }
        sort(s + 1,s + n + 1,cmda);
        cnt[1] = 0;
        for (int i = 1;i <= n && cnt[1] < p;i++)
            if (s[i].a >= s[i].b && s[i].a >= s[i].c && !s[i].ok)
                ans += s[i].a,cnt[1]++,s[i].ok = 1;
        sort(s + 1,s + n + 1,cmdb);
        cnt[2] = 0;
        for (int i = 1;i <= n && cnt[2] < p;i++)
            if (s[i].b >= s[i].a && s[i].b >= s[i].c && !s[i].ok)
                ans += s[i].b,cnt[2]++,s[i].ok = 1;
        sort(s + 1,s + n + 1,cmdc);
        cnt[3] = 0;
        for (int i = 1;i <= n && cnt[3] < p;i++)
            if (s[i].c >= s[i].a && s[i].c >= s[i].b && !s[i].ok)
                ans += s[i].c,cnt[3]++,s[i].ok = 1;
        printf("%lld\n",ans);
    }
    return 0;
}
