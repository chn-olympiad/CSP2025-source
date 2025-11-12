#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,r,ww,a[12][1000005],cost[15];
long long f[1000050];
long long ans=0;
long long num=0;
bool vis[15];
bool A=1;
struct node{
    long long v,w;
};
vector<node>ve[1000050];
struct no{
    long long u,v,w;
};
no roa[1500005];
no roaa[1500055];
bool cmp(no aa,no bb){
    return aa.w<bb.w;
}
long long gettt(long long k){
    if(f[k]==k)return k;
    return f[k]=gettt(f[k]);
}
void merge(long long l,long long r){
    if(gettt(l)!=gettt(r)){
        f[gettt(l)]=gettt(r);
    }
}
long long sum(){
    //cout<<n<<" "<<m<<"**\n\n";
    long long xuansum=0;
    long long maxinum=0;
    long long minn=0;
    for(int i=1;i<=m;i++){
        roaa[i]=roa[i];
    }
    for(int i=1;i<=k;i++){
        if(vis[i]==1){
                minn+=cost[i];
                xuansum++;
            for(int j=1;j<=n;j++){
                maxinum++;
                //cout<<"***"<<m+xuansum<<"***";
                roaa[m+maxinum]={n+xuansum,j,a[i][j]};

            }

        }
    }
    for(int i=1;i<=m+maxinum;i++){
        //cout<<roaa[i].u<<" "<<roaa[i].v<<" "<<roaa[i].w<<"\n";
    }//cout<<"\n\n";
    for(int i=1;i<=n+xuansum;i++)f[i]=i;
        sort(roaa+1,roaa+1+m+maxinum,cmp);
        for(int i=1;i<=m+maxinum;i++){
            long long u=roaa[i].u,v=roaa[i].v,w=roaa[i].w;
            if(gettt(u)!=gettt(v)){
                merge(u,v);
                minn+=w;
            }
        }
    return minn;
}
void dfs(long long d){
    if(d>k){
        ans=min(ans,sum());
        return;
    }
    vis[d]=1;
    dfs(d+1);
    vis[d]=0;
    dfs(d+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>l>>r>>ww;
        roa[i].u=l;
        roa[i].v=r;
        roa[i].w=ww;

        ve[l].push_back({r,ww});
        ve[r].push_back({l,ww});
    }
    for(int i=1;i<=k;i++){
            cin>>cost[i];
            if(cost[i]!=0)A=0;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(k==0){// 没有乡村，直接prim
            for(int i=1;i<=n;i++)f[i]=i;
        sort(roa+1,roa+1+m,cmp);
        for(int i=1;i<=n;i++){
            long long u=roa[i].u,v=roa[i].v,w=roa[i].w;
            if(gettt(u)!=gettt(v)){
                merge(u,v);
                ans+=w;
                num++;
                if(num==n-1)break;
            }

        }
        cout<<ans;
    }
    else if(k<=5){
            ans=99999999999;
        dfs(1);
        cout<<ans;
    }
    else if(A){
        long long xuansum=0;
    long long maxinum=0;
    long long minn=0;
    for(int i=1;i<=10;i++)vis[i]=1;
    for(int i=1;i<=m;i++){
            //vis[i]=1;
        roaa[i]=roa[i];
    }
    for(int i=1;i<=k;i++){
        if(vis[i]==1){
                minn+=cost[i];
                xuansum++;
            for(int j=1;j<=n;j++){
                maxinum++;
                //cout<<"***"<<m+xuansum<<"***";
                roaa[m+maxinum]={n+xuansum,j,a[i][j]};

            }

        }
    }
    for(int i=1;i<=m+maxinum;i++){
        //cout<<roaa[i].u<<" "<<roaa[i].v<<" "<<roaa[i].w<<"\n";
    }//cout<<"\n\n";
    for(int i=1;i<=n+xuansum;i++)f[i]=i;
        sort(roaa+1,roaa+1+m+maxinum,cmp);
        for(int i=1;i<=m+maxinum;i++){
            long long u=roaa[i].u,v=roaa[i].v,w=roaa[i].w;
            if(gettt(u)!=gettt(v)){
                merge(u,v);
                minn+=w;
            }
        }
        cout<<minn;
    }
    else{
            ans=9999999999;
        dfs(1);
        cout<<ans;
    }
    return 0;
}
