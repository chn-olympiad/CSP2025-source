#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct Satisfy{
    int idx,idy,val;
};
const int N=1e5+5;
int nowhave[4],sum[4],a[N],b[N],c[N],val[N][4],opp[N][4];
bool vis[N];
vector<Satisfy> v;
Satisfy make_sat(int idx,int idy,int val){
    Satisfy ans;
    ans.idx=idx;ans.idy=idy;ans.val=val;
    return ans;
}


int max(int x,int y){
    return x>=y?x:y;
}
// const int N=1e5+5;
bool cmp(Satisfy x,Satisfy y){
    if(x.val!=y.val) return x.val>y.val;
    else return sum[x.idy]<sum[y.idy];
    // return x.val>y.val;
}
bool cmp2(Satisfy x,Satisfy y){
    return x.val+opp[x.idx][x.idy]>y.val+opp[x.idx][x.idy];
}
namespace Solve1{
    const int N=1e5+5;
    int a[N],b[N],c[N],n,val[N],maxn=-1;
    int max(int x,int y){
        return x>=y?x:y;
    }
    void dfs(int idx,int rema,int remb,int remc){
        if(idx==n+1){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(val[i]==1) ans+=a[i];
                else if(val[i]==2) ans+=b[i];
                else ans+=c[i];
            }
            maxn=max(maxn,ans);
            return;
        }
        if(rema<n/2){
            val[idx]=1;
            dfs(idx+1,rema+1,remb,remc);
        }
        if(remb<n/2){
            val[idx]=2;
            dfs(idx+1,rema,remb+1,remc);
        }
        if(remc<n/2){
            val[idx]=3;
            dfs(idx+1,rema,remb,remc+1);
        }
        return;
    }
    void solve(int inputn){
        maxn=-1;
        n=inputn;
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        dfs(1,0,0,0);
        printf("%d\n",maxn);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        v.clear();
        sum[1]=sum[2]=sum[3]=0;
        nowhave[1]=nowhave[2]=nowhave[3]=0;
        memset(vis,0,sizeof vis);
        int n;
        scanf("%d",&n);
        if(n<=10){
            Solve1::solve(n);
            continue;
        }
        for(int i=1;i<=n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i]=x;b[i]=y;c[i]=z;
            val[i][1]=x;val[i][2]=y;val[i][3]=z;
            sum[1]+=x;
            sum[2]+=y;
            sum[3]+=z;
            v.push_back(make_sat(i,1,x));
            v.push_back(make_sat(i,2,y));
            v.push_back(make_sat(i,3,z));
        }
        
        
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        sort(c+1,c+n+1);
        int sumupa=0,sumupb=0,sumupc=0;
        for(int i=n;i>n/2;i--){
            sumupa+=a[i];
            sumupb+=b[i];
            sumupc+=c[i];
        }
        for(int i=1;i<=n;i++){
            int cura=sumupa,curb=sumupb,curc=sumupc;
            if(val[i][1]>=a[n/2]) cura-=val[i][1];
            if(val[i][2]>=b[n/2]) curb-=val[i][2];
            if(val[i][3]>=c[n/2]) curc-=val[i][3];
            opp[i][1]=cura+curb+curc;
            opp[i][2]=cura+curb+curc;
            opp[i][3]=cura+curb+curc;
        }
        
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        // for(vector<Satisfy>::iterator it=v.begin();it!=v.end();it++)
        //     if(vis[it->idx]||nowhave[it->idy]==n/2) continue;
        //     else{
        //         if(nowhave[1]==n/2-1||nowhave[2]==n/2-1||nowhave[3]==n/2-1) break;
        //         ans+=it->val;
        //         vis[it->idx]=true;
        //         ++nowhave[it->idy];
        //     }
        sort(v.begin(),v.end(),cmp2);
        for(vector<Satisfy>::iterator it=v.begin();it!=v.end();it++)
            if(vis[it->idx]||nowhave[it->idy]==n/2) continue;
            else{
                ans+=it->val;
                vis[it->idx]=true;
                ++nowhave[it->idy];
                // if(nowhave[1]==n/2||nowhave[2]==n/2||nowhave[3]>n/2) break;
            }
        printf("%d\n",ans);
    }
    return 0;
}