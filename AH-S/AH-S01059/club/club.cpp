#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 100005
using namespace std;
int T,n,id;
struct node{
    ll a,b,c;
}x[N];
ll path[N],cnt[5],ans;
ll pre[N],tot;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        tot=ans=id=cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].b>>x[i].c;
        for(int i=1;i<=n;i++){
            if(x[i].a>=x[i].b&&x[i].a>=x[i].c) path[i]=1,cnt[1]++,ans+=x[i].a;
            else if(x[i].b>=x[i].a&&x[i].b>=x[i].c) path[i]=2,cnt[2]++,ans+=x[i].b;
            else if(x[i].c>=x[i].a&&x[i].c>=x[i].b) path[i]=3,cnt[3]++,ans+=x[i].c;
        }
        for(int i=1;i<=3;i++){
            if(cnt[i]*2>n) id=i;
        }
        if(id){
            for(int i=1;i<=n;i++){
                if(path[i]==id){
                    if(id==1) pre[++tot]=min(x[i].a-x[i].b,x[i].a-x[i].c);
                    if(id==2) pre[++tot]=min(x[i].b-x[i].a,x[i].b-x[i].c);
                    if(id==3) pre[++tot]=min(x[i].c-x[i].b,x[i].c-x[i].a);
                }
            }
            sort(pre+1,pre+1+tot);
            for(int i=1;i<=cnt[id]-n/2;i++){
                ans-=pre[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
