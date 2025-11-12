#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
struct noid{
    int x,y,z,k;
}a[N],b[N];
bool cmp(const noid&a,const noid&b){
    return a.z<b.z;
}
int c[20];
int p[10020];
int zzz(int x){
    if(p[x]!=x){
        p[x]=zzz(p[x]);
    }
    return p[x];
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>b[i].x>>b[i].y>>b[i].z;
    }
    sort(b+1,b+1+m,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=1;i<=m;i++){
        if(zzz(b[i].x)!=zzz(b[i].y)){
            p[zzz(b[i].x)]=zzz(b[i].y);
            cnt++;
            a[cnt].x=b[i].x;
            a[cnt].y=b[i].y;
            a[cnt].z=b[i].z;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cnt++;
            a[cnt].x=j;
            a[cnt].y=n+i;
            a[cnt].k=i;
            cin>>a[cnt].z;
        }
    }
    sort(a+1,a+1+cnt,cmp);
    int minn=1e18;
    for(int s=0;s<(1<<k);s++){
        for(int i=1;i<=n+k;i++){
            p[i]=i;
        }
        int ans=0,sum=n,con=0;
        for(int i=1;i<=k;i++){
            if(s&(1<<(i-1))){
                sum++;
                ans+=c[i];
            }
        }
        for(int i=1;i<=cnt;i++){
            if(con==sum){
                break;
            }
            if(a[i].k==0||(s&(1<<(a[i].k-1)))){
                if(zzz(a[i].x)!=zzz(a[i].y)){
                    p[zzz(a[i].x)]=zzz(a[i].y);
                    ans+=a[i].z;
                    con++;
                }
            }
        }
        minn=min(minn,ans);
        // cout<<ans<<" ";
    }
    cout<<minn;
    return 0;
}
