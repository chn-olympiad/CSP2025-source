#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<cstring>
using namespace std;
constexpr int N=1e5+5;
array<int,3> a[N],sum[N];
int mx[3];
int n;
int f[N][3],cnt[N][3];
int ans0;
int sum01[N],sum12[N],sum02[N];
int last[3];
void dfs(int pos,int sum,int c1,int c2,int c3){
    if(pos>n){
        ans0=max(ans0,sum);
        return;
    }
    if(c1<n/2) dfs(pos+1,sum+a[pos][0],c1+1,c2,c3);
    if(c2<n/2) dfs(pos+1,sum+a[pos][1],c1,c2+1,c3);
    if(c3<n/2) dfs(pos+1,sum+a[pos][2],c1,c2,c3+1);
}
void move0(int &x1,int &y1,int x2,int y2){
    if(x2>x1) x1=x2,y1=y2+1;
}
void work(){
    cin>>n;
    mx[0]=0,mx[1]=0,mx[2]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+a[i][j];
            mx[j]=max(mx[j],a[i][j]);
        }
        sum01[i]=sum01[i-1]+max(a[i][0],a[i][1]);
        sum12[i]=sum12[i-1]+max(a[i][2],a[i][1]);
        sum02[i]=sum02[i-1]+max(a[i][0],a[i][2]);
    }
    if(mx[0]==0&&mx[1]==0&&mx[2]==0){
        cout<<0<<'\n';
    }
    else if(mx[1]==0&&mx[2]==0){
        auto cmp=[&](const array<int,3>& l,const array<int,3>& r)->bool {
            return l[0]>r[0];
        };
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++) ans+=a[i][0];
        cout<<ans<<'\n';
    }
    else if(mx[0]==0&&mx[2]==0){
        auto cmp=[&](const array<int,3>& l,const array<int,3>& r)->bool {
            return l[1]>r[1];
        };
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++) ans+=a[i][1];
        cout<<ans<<'\n';
    }
    else if(mx[0]==0&&mx[1]==0){
        auto cmp=[&](const array<int,3>& l,const array<int,3>& r)->bool {
            return l[2]>r[2];
        };
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++) ans+=a[i][2];
        cout<<ans<<'\n';
    }
    else if(n<=10){
        ans0=0;
        dfs(1,0,0,0,0);
        cout<<ans0<<'\n';
    }
    // else if(mx[2]==0){
    //     memset(f,-1,sizeof(f));
    //     for(int i=1;i<=n;i++){
    //         if(cnt[i-1][0]<n/2) move0(f[i][0],cnt[i][0],f[i-1][0]+a[i][0],cnt[i-1][0]);
    //         else{
    //             for(int j=1;j<i;j++){
    //                 if(cnt[j][0]<n/2) move0(f[i][0],cnt[i][0],f[j][0]+sum[i][1]-sum[j][1],cnt[i-1][0]);
    //             }
    //         }
    //     }
    // }
    else{
        memset(f,-1,sizeof(f));
        for(int i=1;i<=n;i++){
            int mx=-1,c=-1;
            for(int j=0;j<3;j++){
                if(cnt[i-1][0]<n/2) move0(f[i][j],cnt[i][j],f[i-1][0]+a[i][j],cnt[i-1][0]);
                else move0(f[i][j],cnt[i][j],f[last[0]][0]+sum12[i]-sum12[last[0]],(n/2)+1);
                if(cnt[i-1][1]<n/2) move0(f[i][j],cnt[i][j],f[i-1][1]+a[i][j],cnt[i-1][1]);
                else move0(f[i][j],cnt[i][j],f[last[1]][1]+sum02[i]-sum02[last[1]],(n/2)+1);
                if(cnt[i-1][2]<n/2) move0(f[i][j],cnt[i][j],f[i-1][2]+a[i][j],cnt[i-1][2]);
                else move0(f[i][j],cnt[i][j],f[last[2]][2]+sum01[i]-sum01[last[2]],(n/2)+1);
                if(cnt[i][0]==(n/2)-1) last[0]=i;
                else if(cnt[i][1]==(n/2)-1) last[1]=i;
                else if(cnt[i][2]==(n/2)-1) last[2]=i;
            }
        }
        cout<<max({f[n][0],f[n][1],f[n][2]})<<'\n';
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    // cin.tie(nullptr)->sync_with_stdio(0);
    int t;
    for(cin>>t;t;t--) work();
    return 0;
}