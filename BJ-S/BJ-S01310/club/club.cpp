#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct student{
    int x,y,z;
    ll sum;
    bool operator<(const student &o)const{
        return x>o.x;
    }
}a[N];
bool cmp(student q,student e){
    return q.x>e.x;
}
bool cmp1(student q,student e){
    return q.sum>e.sum;
}
ll n,vis[N],b[N][4];
ll ans,he[N][4];
void dfs(int k,ll sum,int id){
    //cout<<k<<" "<<sum<<" "<<id<<endl;
    if(k==2*n){
        ans=max(ans,sum);
        return;
    }
    if(k%2==0){
        for(int i=id+1;i<=n;i++){
            dfs(k+1,sum,i);
        }
    }else{
        for(int i=1;i<=3;i++){
            if(vis[i]>=n/2) continue;
            //cout<<i<<endl;
            vis[i]++;
            if(i==1){
                dfs(k+1,sum+a[id].x,id);
            }else if(i==2){
                dfs(k+1,sum+a[id].y,id);
            }else{
                dfs(k+1,sum+a[id].z,id);
            }
            vis[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        memset(he,0,sizeof(he));
        bool flag=1;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
            if(a[i].y!=0||a[i].z!=0) flag=0;
            a[i].sum=a[i].x+a[i].y+a[i].z;
        }
        //cout<<flag<<endl;
        if(flag){
            ll ans=0;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[i].x;
            }
            printf("%lld\n",ans);
            continue;
        }
        if(n<=14){
            dfs(1,0ll,1);
            printf("%lld\n",ans);
            continue;
        }
        //
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++){
            b[i][1]=a[i].x;
            b[i][2]=a[i].y;
            b[i][3]=a[i].z;
            for(int j=1;j<=3;j++){
                he[i][j]=max(he[i-1][j],b[i][j]);
            }
        }
        for(int i=1;i<=n;i+=2){
            int id1,id2,maxx=0;
            for(int j=1;j<=3;j++){
                if(vis[j]>=n/2) continue;
                vis[j]++;
                for(int k=1;k<=3;k++){
                    if(vis[k]>=n/2) continue;
                    if(maxx<b[i][j]+b[i+1][k]){
                        maxx=b[i][j]+b[i+1][k];
                        id1=j;id2=k;
                    }
                    else if(maxx==b[i][j]+b[i+1][k]){
                        if(id1==j){
                            if(he[n][id2]>he[n][k]){
                                id2=k;
                            }
                        }else if(id2==k){
                            if(he[n][id1]>he[n][j]){
                                id1=j;
                            }
                        }
                    }
                }
                vis[j]--;
            }
            vis[id1]++;
            vis[id2]++;
            ans+=maxx;
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}