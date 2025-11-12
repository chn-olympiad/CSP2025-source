#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n;
struct node{
    int id,lx,val;
};
int l[100005][4];
node p[350005];
int cnt[5];
int s[4][100005];
bool vis[100005];
int flag=0;
int cnt4=0;
int q[100005];
int a[5];
ll ans;
bool cmp(node a,node b){
    return a.val>b.val;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        cnt4=0;
        memset(vis,0,sizeof(vis));
        memset(q,0,sizeof(q));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[1]>>a[2]>>a[3];
            for(int j=1;j<=3;j++){
                p[++cnt4].id=i;
                p[cnt4].lx=j;
                p[cnt4].val=a[j];
            }
            l[i][1]=a[1];
            l[i][2]=a[2];
            l[i][3]=a[3];
        }
        sort(p+1,p+cnt4+1,cmp);
        for(int i=1;i<=cnt4;i++){
            if(vis[p[i].id]==1){
                continue;
            }
            ans=ans+p[i].val;
            vis[p[i].id]=1;
            cnt[p[i].lx]++;
            s[p[i].lx][cnt[p[i].lx]]=p[i].id;
        }
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2){
                for(int j=1;j<=cnt[i];j++){
                    int maxn=0;
                    for(int k=1;k<=3;k++){
                        if(k==i){
                            continue;
                        }
                        maxn=max(l[s[i][j]][k],maxn);
                    }
                    q[j]=l[s[i][j]][i]-maxn;
                }
                sort(q+1,q+cnt[i]+1);
                for(int j=1;j<=cnt[i]-n/2;j++){
                    ans-=q[j];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
