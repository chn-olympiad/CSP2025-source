#include <bits/stdc++.h>
using namespace std;
int n,vis[200000],ans,i,j,k,ca,cb,cc,cnt;
struct d{
    int v;
    int idx;
};
d a[200000],b[200000],c[200000];
int s[3][200000],r[3];
void dfs(int i,int sum){
    if(i==n+1) ans=max(ans,sum);
    for(int j=0;j<3;j++){
        if(r[j]<n/2){
            r[j]++;
            dfs(i+1,sum+s[j][i]);
            r[j]--;
        }
    }
}
bool cmp(d x,d y){
    return x.v>y.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<200){
            ans=0;
            for(int i=1;i<=n;i++){
                cin>>s[0][i]>>s[1][i]>>s[2][i];
            }
            dfs(1,0);
            cout<<ans<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            cin>>a[i].v>>b[i].v>>c[i].v;
            a[i].idx=b[i].idx=c[i].idx=i;
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        sort(c,c+n,cmp);
        i=0,j=0,k=0,ca=0,cb=0,cc=0,ans=0,cnt=0;
        memset(vis,0,sizeof(vis));
        while(cnt<n){
            while(vis[a[i].idx]) i++;
            while(vis[b[j].idx]) j++;
            while(vis[c[k].idx]) k++;
            if(a[i].v>=b[j].v&&a[i].v>=c[k].v&&vis[a[i].idx]==0&&ca<n/2){
                ans+=a[i].v;
                vis[a[i].idx]=1;
                i++;
                ca++;
            }
            else if(b[j].v>=a[i].v&&b[j].v>=c[k].v&&vis[b[j].idx]==0&&cb<n/2){
                ans+=b[j].v;
                vis[b[j].idx]=1;
                j++;
                cb++;
            }
            else if(c[k].v>=b[j].v&&c[k].v>=a[i].v&&vis[c[k].idx]==0&&cc<n/2){
                ans+=c[k].v;
                vis[c[k].idx]=1;
                k++;
                cc++;
            }
            cnt++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


