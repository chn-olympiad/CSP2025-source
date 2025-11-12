#include<iostream>
#include<algorithm>
#include<climits>
#define maxn 100005
using namespace std;
int n,ans,cnt[4],x,y,z,tt,t1;
struct e{
    int i,v[4],d,g;
}a[maxn],c[4][maxn];
bool cmp(e a,e b){
    return a.d>b.d;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t1;
    while(t1--){
    ans=0;
    cin>>n;
    if(n&1)cout<<"我知道你想淦什么，哈哈哈\n\n\n我是击掰坨似的三狼，，击败！"<<endl;
    cnt[1]=cnt[2]=cnt[3]=0;
    for(int i = 1;i<=n;i++){
        cin>>x>>y>>z;
        a[i].i=i;
        a[i].v[1]=x;
        a[i].v[2]=y;
        a[i].v[3]=z;
        if(x==y&&y==x&&z==x){
            c[0][++cnt[0]]=a[i];
            continue;
        }
        if(x>=y&&x>=z){
            c[1][++cnt[1]]=a[i];
        }
        else if(y>=x&&y>=z){
            c[2][++cnt[2]]=a[i];
        }
        else if(z>=x&&z>=y){
            c[3][++cnt[3]]=a[i];
        }
    }
    int n2=n/2;
    for(tt=1;tt<=3;tt++){
        if(cnt[tt]>n2){
            //cout<<tt<<"dayu"<<cnt[tt]<<endl;
            int t1=0,t2=0;
            if(tt==1){
                t1=2;
                t2=3;
            }
            if(tt==2){
                t1=1;
                t2=3;
            }
            if(tt==3){
                t1=2;
                t2=1;
            }
            for(int i = 1;i<=cnt[tt];i++){
                c[tt][i].g=max(c[tt][i].v[t1],c[tt][i].v[t2]);
                c[tt][i].d=c[tt][i].v[tt]-c[tt][i].g;
            }
            sort(c[tt]+1,c[tt]+cnt[tt]+1,cmp);
            for(int i = 1;i<=n2;i++){
                ans+=c[tt][i].v[tt];
            }
            for(int i = n2+1;i<=cnt[tt];i++){
                ans+=c[tt][i].g;
            }
        }
        else for(int i = 1;i<=n2&&i<=cnt[tt];i++){
            ans+=c[tt][i].v[tt];
        }
    }
    for(int i = 1;i<=cnt[0];i++){
        ans+=c[0][i].v[1];
    }
    cout<<ans<<endl;
    }
    return 0;
}

