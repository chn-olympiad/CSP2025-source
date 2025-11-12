#include<bits/stdc++.h>
using namespace std;
int n,ans,num[114514];
void dfs(int sum,int k,int d){
    if(d>=2&&sum>num[k]) ans++;
    if(k==n) return;
    dfs(sum+num[k],k+1,d+1);
    dfs(sum,k+1,d);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    sort(num+1,num+n+1);
    dfs(0,1,0);
    printf("%d",ans);
    return 0;
}
/*
const int maxn=5000*5000+1145;
int n,a1[5050],a2[maxn],a3[maxn],cnt1,cnt2,cnt3,ans;
const int mod=988244353;
map<int,int> mp1;
map<int,int> mp2;
map<int,int> mp3;
void check(){
    for(int i=1;i<=cnt1;i++) printf("%d %d\n",a1[i],mp1[a1[i]]);
    puts("--------------------------------------------------1");
    for(int i=1;i<=cnt2;i++) printf("%d %d\n",a2[i],mp2[a2[i]]);
    puts("--------------------------------------------------2");
    for(int i=1;i<=cnt3;i++) printf("%d %d\n",a3[i],mp3[a3[i]]);
    puts("--------------------------------------------------3");
    printf("%d\n",ans);
    puts("------------------------------------------------ans");
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        int cnt=cnt3;
        for(int i=1;i<=cnt;i++){
            if(a3[i]>x) ans=(ans+mp3[a3[i]])%mod;
            if(!mp3[a3[i]+x]) a3[++cnt3]=a3[i]+x;
            mp3[a3[i]+x]+=mp3[a3[i]];
        }
        for(int i=1;i<=cnt2;i++){
            if(a2[i]>x) ans=(ans+mp2[a2[i]])%mod;
            if(!mp3[a2[i]+x]) a3[++cnt3]=a2[i]+x;
            mp3[a2[i]+x]+=mp2[a2[i]];
        }
        for(int i=1;i<=cnt1;i++){
            if(!mp2[a1[i]+x]) a2[++cnt2]=a1[i]+x;
            mp2[a1[i]+x]+=mp1[a1[i]];
        }
        if(!mp1[x]){
            cnt1++;
            a1[cnt1]=x;
        }
        mp1[x]++;
        //check();
    }

    printf("%d",ans);
    return 0;
}
最后发现不如暴力dfs(
dfs稳拿40pts
估计总分300pts
稳拿1=
剩下20+min

蛋仔ID 窝不甘心！
有人加好友么
*/
