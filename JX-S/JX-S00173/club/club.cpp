#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+2;
struct node{int x,y,z;}a[N];
int num[N][3],cnt[3],id[N];
struct stu{int d,to,p;}tmp[N<<1];
bool cmp(stu x,stu y){return x.d>y.d;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ll n,ans=0;
        cin>>n;
        cnt[0]=cnt[1]=cnt[2]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            int mx=max(max(a[i].x,a[i].y),a[i].z);
            if(mx==a[i].x) ans+=a[i].x,num[++cnt[0]][0]=i,id[i]=0;
            else if(mx==a[i].y) ans+=a[i].y,num[++cnt[1]][1]=i,id[i]=1;
            else ans+=a[i].z,num[++cnt[2]][2]=i,id[i]=2;
        }
        if(cnt[0]>n/2){
            for(int i=1;i<=cnt[0];i++){
                int now=num[i][0];
                tmp[i*2-1]={a[now].y-a[now].x,1,now};
                tmp[i*2]={a[now].z-a[now].x,2,now};
            }
            sort(tmp+1,tmp+1+2*cnt[0],cmp);
            for(int i=1;i<=cnt[0]*2;i++){
                int d=tmp[i].d,to=tmp[i].to,now=tmp[i].p;
                if(cnt[to]>=n/2||id[now]!=0) continue;
                cnt[0]--,cnt[to]++,ans+=d,id[now]=to;
                if(cnt[0]<=n/2) break;
            }
        }
        else if(cnt[1]>n/2){
            for(int i=1;i<=cnt[1];i++){
                int now=num[i][1];
                tmp[i*2-1]={a[now].x-a[now].y,0,now};
                tmp[i*2]={a[now].z-a[now].y,2,now};
            }
            sort(tmp+1,tmp+1+2*cnt[1],cmp);
            for(int i=1;i<=cnt[1]*2;i++){
                int d=tmp[i].d,to=tmp[i].to,now=tmp[i].p;
                if(cnt[to]>=n/2||id[now]!=1) continue;
                cnt[1]--,cnt[to]++,ans+=d,id[now]=to;
                if(cnt[1]<=n/2) break;
            }
        }
        else if(cnt[2]>n/2){
            for(int i=1;i<=cnt[2];i++){
                int now=num[i][2];
                tmp[i*2-1]={a[now].y-a[now].z,1,now};
                tmp[i*2]={a[now].x-a[now].z,0,now};
            }
            sort(tmp+1,tmp+1+2*cnt[2],cmp);
            for(int i=1;i<=cnt[2]*2;i++){
                int d=tmp[i].d,to=tmp[i].to,now=tmp[i].p;
                if(cnt[to]>=n/2||id[now]!=2) continue;
                cnt[2]--,cnt[to]++,ans+=d,id[now]=to;
                if(cnt[2]<=n/2) break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}