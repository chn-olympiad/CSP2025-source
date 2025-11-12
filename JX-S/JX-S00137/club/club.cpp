#include<bits/stdc++.h>
using namespace std;
long long n,t,s,ah,bh,ch,maxn;
struct club{
    long long num,like;
};
club a[100005],b[100005],c[100005];

void dfs(long long x){
    //cout<<s<<' '<<maxn<<endl;
    //int we=ah+bh+ch;
    long long sum=0;
    if(ah<n/2){
        ah++;
        s+=a[x].like;
        dfs(x+1);
        s-=a[x].like;
        ah--;
    }
    else{
        sum=0;
        for(long long i=x;i<=n;i++){
            sum+=max(c[i].like,b[i].like);
        }
        maxn=max(maxn,s+sum);
        return;
    }
    if(bh<n/2){
        bh++;
        s+=b[x].like;
        dfs(x+1);
        s-=b[x].like;
        bh--;
    }
    else{
        sum=0;
        for(long long i=x;i<=n;i++){
            sum+=max(a[i].like,c[i].like);
        }
        maxn=max(maxn,s+sum);
        return;
    }
    if(ch<n/2){
        ch++;
        s+=c[x].like;
        dfs(x+1);
        s-=c[x].like;
        ch--;
    }
    else{
        sum=0;
        for(long long i=x;i<=n;i++){
            sum+=max(a[i].like,b[i].like);
        }
        maxn=max(maxn,s+sum);
        return;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(long long i=1;i<=t;i++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        s=0;maxn=0;
        scanf("%lld",&n);
        for(long long j=1;j<=n;j++){
            scanf("%lld%lld%lld",&a[j].like,&b[j].like,&c[j].like);
            a[j].num=b[j].num=c[j].num=i;
        }
        dfs(1);
        printf("%lld\n",maxn);
    }
    return 0;
}
