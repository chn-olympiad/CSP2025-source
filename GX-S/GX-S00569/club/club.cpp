#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n;
struct node{
    int a,b,c;
    int maxx,maxid;
    int sec,secid;
}s[N];
bool cmp(node x,node y){
    return x.maxx-x.sec>y.maxx-y.sec;
}
int p[3];
long long ans;
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
        s[i].maxx=max(s[i].a,max(s[i].b,s[i].c));
        if(s[i].maxx==s[i].a){
            s[i].maxid=0;
            s[i].sec=max(s[i].b,s[i].c);
            if(s[i].b>=s[i].c) s[i].secid=1;
            else s[i].secid=2;
        }
        else if(s[i].maxx==s[i].b){
            s[i].maxid=1;
            s[i].sec=max(s[i].a,s[i].c);
            if(s[i].a>=s[i].c) s[i].secid=0;
            else s[i].secid=2;
        }
        else{
            s[i].maxid=2;
            s[i].sec=max(s[i].a,s[i].b);
            if(s[i].a>=s[i].b) s[i].secid=0;
            else s[i].secid=1;
        }
    }
    sort(s+1,s+1+n,cmp);
    p[1]=p[2]=p[0]=0;
    ans=0;
    for(int i=1;i<=n;i++){
        if(p[s[i].maxid]==n/2){
            ans+=s[i].sec;
            p[s[i].secid]++;
        }
        else {
            ans+=s[i].maxx;
            p[s[i].maxid]++;
        }
        s[i]={0,0,0,0,0,0,0};
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
