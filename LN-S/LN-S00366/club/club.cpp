#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005][5];
int ch[100005];
int dt[100005];
int cnt[5];
int mx(int i){
    if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])return 1;
    if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])return 2;
    if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2])return 3;
    return 0;
}
void sv(){
    int n; scanf("%d",&n); long long ans = 0; int tot = 0;
    for(int i = 1;i <= 3;i++)cnt[i] = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        int j = mx(i); ch[i] = j; cnt[j]++; ans+= a[i][j];
    }
    int j = 0; for(int i = 1;i <= 3;i++)if(cnt[i] > n/2)j = i;
    if(!j){printf("%lld\n",ans); return;} swap(cnt[1],cnt[j]);
    for(int i = 1;i <= n;i++){
        if(ch[i] != j)continue; swap(a[i][1],a[i][j]);
        tot++; dt[tot] = a[i][1]-max(a[i][2],a[i][3]);
    }
    sort(dt+1,dt+tot+1);
    for(int i = 1;i <= tot - n/2; i++)ans-= dt[i];
    printf("%lld\n",ans); return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; scanf("%d",&t);
    for(int i = 1;i <= t;i++)sv();
    return 0;
}