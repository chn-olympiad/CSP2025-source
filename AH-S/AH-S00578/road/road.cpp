#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> ss0[10050][2];
int c[11][10005];
long long ans=1e18;
long long st(int x){
    long long sum=0;
    int i=1;
    while(x>0){
        if(x&1)
            sum+=c[i][0];
        x/=2;
        i++;
    }
    return sum;
}
vector<int> ss[10050][2];
bool fl[10050];
long long sd[10050];
long long cost(int x){
    memset(fl,0,sizeof(fl));
    memset(sd,0x3f,sizeof(sd));
    for(int i=1;i<=n;i++)
        ss[i][0]=ss0[i][0],ss[i][1]=ss0[i][1];
    long long cos=0;
    int id=0,zxcv=0;
    while(x>0){
		id++;
        if(x&1){
			zxcv++;
            for(int j=1;j<=n;j++){
                ss[n+zxcv][0].push_back(j);ss[n+zxcv][1].push_back(c[id][j]);
                ss[j][0].push_back(n+zxcv);ss[j][1].push_back(c[id][j]);
            }
        }
        x/=2;
    }
    int nn=n+zxcv;sd[1]=0;
    int topfirst,topsecond;
    for(int qwer=1;qwer<=nn;qwer++){
        long long minn=sd[0];id=1;
        for(int i=1;i<=nn;i++)
        if(fl[i]==0&&sd[i]<minn){
            minn=sd[i];
            id=i;
        }
        fl[id]=1;cos+=minn;
        for(int yu=0;yu<ss[id][0].size();yu++)
            if(fl[topfirst]==0){
                topfirst=ss[id][0][yu];
                topsecond=ss[id][1][yu];
                sd[topfirst]=min(sd[topfirst],1ll*topsecond);
            }
    }
    return cos;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        ss0[u][0].push_back(v);ss0[u][1].push_back(w);
        ss0[v][0].push_back(u);ss0[v][1].push_back(w);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i][0]);
        for(int j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    }
    for(int i=0;i<(1<<k);i++)
		ans=min(ans,cost(i)+st(i));
    printf("%lld\n",ans);
    return 0;
}
