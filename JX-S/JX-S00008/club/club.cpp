#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans,cnt[3];
struct node{
    int a[3];
    int id,maxn,sep,mid,sid,low,lid;
    bool operator <(const node &x){
        if(maxn-sep == x.maxn-x.sep)
        return maxn > x.maxn;
        return maxn-sep > x.maxn-x.sep;
    }
}p[N];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T; while(T--){
        cin>>n;
        cnt[0]=cnt[1]=cnt[2]=0;
        memset(p,0,sizeof(p));
        for(int i=1;i<=n;++i){
            p[i].id=i;
            for(int k=0;k<3;++k){
                cin>>p[i].a[k];
                if(p[i].maxn<p[i].a[k])
                p[i].sep=p[i].maxn,p[i].sid=p[i].mid,
                p[i].maxn=p[i].a[k],p[i].mid=k;
                else if(p[i].sep<p[i].a[k])
                p[i].low=p[i].sep,p[i].lid=p[i].sid,
                p[i].sep=p[i].a[k],p[i].sid=k;
                else if(p[i].low<p[i].a[k])
                p[i].low=p[i].a[k],p[i].lid=k;
            }
        }ans=0;
        sort(p+1,p+n+1);
        int lim=n/2;
        for(int i=1;i<=n;++i){
            if(cnt[p[i].mid]<lim){
                ans+=p[i].maxn;
                cnt[p[i].mid]++;
            }
            else{
                if(cnt[p[i].sid]<lim){
                    ans+=p[i].sep;
                    cnt[p[i].sid]++;
                }
                else{
                    ans+=p[i].low;
                    cnt[p[i].lid]++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
