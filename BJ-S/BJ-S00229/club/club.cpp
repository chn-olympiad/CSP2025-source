#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
const int maxn=1e5+10,inf=1e17;
int t,n,cnt[3];
struct NODE{
    int v[3],mx,df,id;
}a[maxn];
bool cmp1(NODE x,NODE y){
    return x.mx>y.mx;
}
bool cmp2(NODE x,NODE y){
    return x.df<y.df;
}
int findid(){
    int mx=0,id=0;
    for(int i=0;i<3;i++){
        if(mx<cnt[i])mx=cnt[i],id=i;
        // cout<<cnt[i]<<' ';
    }
    // cout<<'\n';
    return id;
}
int gtsc(int i){
    return max(a[i].v[0],a[i].v[1])+max(a[i].v[0],a[i].v[2])+max(a[i].v[1],a[i].v[2])-2*a[i].mx;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cnt[0]=cnt[1]=cnt[2]=0;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i].v[j];
                if(a[i].v[j]>a[i].mx){
                    a[i].mx=a[i].v[j];
                    a[i].id=j;
                }
                a[i].df=a[i].mx-gtsc(i);
            }
        }
        sort(a+1,a+n+1,cmp1);
        int ans=0,id;
        for(int i=1;i<=n;i++){
            ans+=a[i].mx;
            cnt[a[i].id]++;
        }
        id=findid();
        sort(cnt,cnt+3);
        int pos=0;
        if(cnt[2]>n/2)pos=cnt[2]-n/2;
        else{
            cout<<ans<<'\n';
            continue;
        }
        // cout<<ans<<' '<<id<<'\n';
        sort(a+1,a+n+1,cmp2);
        int ctid=0;
        for(int i=1;i<=n&&ctid<pos;i++){
            if(a[i].id==id){
                ctid++;
                ans-=a[i].df;
            }
        }
        cout<<ans<<'\n';
    }
}
//Ren5Jie4Di4Ling5%