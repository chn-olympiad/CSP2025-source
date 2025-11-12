#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
inline ll read(){
    ll num=0,sign=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        sign=ch=='-'?-1:1,ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    }
    return sign>0?num:-num;
}
ll T,n,ans,cnt[5];
struct node{
    ll v,id,d;
}a[N];
bool cmp(node x,node y){
    return x.v>y.v;
}
bool vis[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll max_=-1,cnt1=0;
    memset(vis,0,sizeof(vis));
    T=read();
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        cnt1=0,max_=-1,ans=0;
        n=read();
        int p=n/2;
        for(int i=1;i<=3*n;i++){
            a[i].v=read(),a[i].d=i%3;
            a[i].id=i%3==0?i/3:i/3+1;
        }
        sort(a+1,a+1+3*n,cmp);
        int k=1;
        while(k<=3*n && cnt1<=n){
            if(cnt[a[k].d]<p && vis[a[k].id]==0)
                ans+=a[k].v,cnt[a[k].d]++,vis[a[k].id]=1,k++,cnt1++;
            else if(cnt[a[k].d]>=p && vis[a[k].id]==0){
                for(int i=k+1;i<=3*n;i++){
                    if(a[i].id==a[k].id)
                        ans+=a[i].v,cnt[a[i].d]++,vis[a[i].id]=1,k++,cnt1++;
                }
            }
            else if(vis[a[k].id]==1)
                k++;
            if(ans==a[1].v && cnt1==n)
                    k=2,memset(vis,0,sizeof(vis)),memset(cnt,0,sizeof(cnt)),ans=0,cnt1=0;
            else if(cnt1==n){
                max_=max(max_,ans);
                printf("%lld\n",max_);
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
