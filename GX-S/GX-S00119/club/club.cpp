#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
int t;
int n;
struct E{int w,num,club;} stu[N*3];
int c[4],f[N][4],clu[4][N];
bool vis[N];
int ans;
int read(){
    int f=1,x=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')    f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f*x;
}

bool cmp(E x,E y){
    return x.w>y.w;
}

bool cmp2(int x,int y){
    return x>y;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        memset(vis,0,sizeof vis);
        memset(c,0,sizeof c);
        memset(f,0,sizeof f);
        memset(clu,0,sizeof clu);
        ans=0;
        int idx=0;
        n=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                stu[++idx].w=read();
                stu[idx].num=i;
                stu[idx].club=j;
                f[i][j]=stu[idx].w;
            }
        }
        if(n<=30){
        sort(stu+1,stu+n*3+1,cmp);
        for(int i=1;i<=3*n;i++){
            if(vis[stu[i].num])  continue;
            if(c[stu[i].club]<n/2){
                c[stu[i].club]++;
                clu[stu[i].club][c[stu[i].club]]=stu[i].num;
                vis[stu[i].num]=1;
                ans+=stu[i].w;
                continue;
            }
            int repla=0,id=0,cho=0;
            for(int j=1;j<=c[stu[i].club];j++){
                int name=clu[stu[i].club][j];
                //cout<<name<<" ";
                for(int k=1;k<=3;k++){
                    if(k==stu[i].club)  continue;
                    if(f[name][k]>=repla)    repla=f[name][k],cho=k,id=name;
                }
            }
            int now=f[id][stu[i].club];
            int res=stu[i].w+repla;
            //cout<<repla<<" "<<now<<endl;
            if(res>now){
                ans=ans-now+res;
                c[cho]++;
            }
            //cout<<stu[i].num<<" "<<stu[i].club<<endl;
        }
        cout<<ans<<endl;
        break;
        }
        for(int i=1;i<=n*3;i++){
            ans=max(stu[i].w,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
