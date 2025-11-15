#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20,maxm=1e6+5;
struct node{
    int x,y,z;
};
bool operator<(node y,node x){
    return x.z>y.z;
}
vector<node>d,d2,ANS;
int f[maxn],c[25],v[25][maxn];
int n,m,K,x,y,z;
long long ans=0;
bool USED[maxn];
int get_f(int now){
    if(f[now]==now)return now;
    return f[now]=get_f(f[now]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=n+K;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        d.push_back({x,y,z});
        // cout<<x<<" "<<y<<" "<<z<<endl;
    }
    for(int i=1;i<=K;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            USED[j]=true;
            scanf("%d",&v[i][j]);
            d2.push_back({n+i,j,v[i][j]});
        }
    }
    sort(d.begin(),d.end());
    sort(d2.begin(),d2.end());
    for(int i=0;i<m;i++){
        // cout<<i<<endl;
        // cout<<d[i].x<<" "<<d[i].y<<" "<<d[i].z<<endl;
        int l=get_f(d[i].x),r=get_f(d[i].y);
        if(l==r)continue;
        ans+=d[i].z;
        f[l]=r;
        ANS.push_back(d[i]);
    }
    // cout<<"ANS\n";
    // for(int i=0;i<n-1;i++)cout<<ANS[i].x<<" "<<ANS[i].y<<" "<<ANS[i].z<<endl;
    // cout<<"D2\n";
    // for(int i=0;i<=n*K-1;i++)cout<<d2[i].x<<" "<<d2[i].y<<" "<<d2[i].z<<endl;
    
    for(int i=1;i<(1<<K);i++){
        // cout<<"I:"<<i<<endl;
        long long tmp_ans=0;
        int CNT=0;
        for(int j=1;j<=n;j++)f[j]=j;
        for(int j=1;j<=K;j++){
            f[n+j]=n+j;
            if(i&(1<<(j-1)))CNT++,tmp_ans+=c[j],USED[n+j]=true;
            else USED[n+j]=false;
        }
        int pos1=0,pos2=0,line=0;
        while(line!=n+CNT-1&&pos1<n-1&&pos2<=n*K-1){
            if(ANS[pos1].z<d2[pos2].z){
                int l=get_f(ANS[pos1].x),r=get_f(ANS[pos1].y);
                if(l==r){
                    pos1++;
                    continue;
                }
                // cout<<ANS[pos1].x<<" "<<ANS[pos1].y<<" "<<ANS[pos1].z<<endl;
                tmp_ans+=ANS[pos1].z;
                f[l]=r;
                line++;
                pos1++;
            }
            else{
                if(!USED[d2[pos2].x]||!USED[d2[pos2].y]){
                    pos2++;
                    continue;
                }
                int l=get_f(d2[pos2].x),r=get_f(d2[pos2].y);
                if(l==r){
                    pos2++;
                    continue;
                }
                // cout<<d2[pos2].x<<" "<<d2[pos2].y<<" "<<d2[pos2].z<<endl;
                tmp_ans+=d2[pos2].z;
                f[l]=r;
                line++;
                pos2++;
            }
        }
        while(line!=n+CNT-1&&pos1<n-1){
            int l=get_f(ANS[pos1].x),r=get_f(ANS[pos1].y);
            if(l==r){
                pos1++;
                continue;
            }
            // cout<<ANS[pos1].x<<" "<<ANS[pos1].y<<" "<<ANS[pos1].z<<endl;
            tmp_ans+=ANS[pos1].z;
            f[l]=r;
            line++;
            pos1++;
        }
        while(line!=n+CNT-1&&pos2<=n*K-1){
            
            if(!USED[d2[pos2].x]||!USED[d2[pos2].y]){
                pos2++;
                continue;
            }
            int l=get_f(d2[pos2].x),r=get_f(d2[pos2].y);
            if(l==r){
                pos2++;
                continue;
            }
            // cout<<d2[pos2].x<<" "<<d2[pos2].y<<" "<<d2[pos2].z<<endl;
            tmp_ans+=d2[pos2].z;
            f[l]=r;
            line++;
            pos2++; 
        }
        ans=min(ans,tmp_ans);
    }
    printf("%lld\n",ans);
    // cout<<ans<<endl;
    return 0;
}