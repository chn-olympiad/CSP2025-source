#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+100;
const int N=1e4+100;
struct st{
    int u,v,val;
};
int cnt;
st line[M+10*N];
bool bo[12][N];
int a[12][N];
int c[12];
int n,m,k;
long long ans;
int bcj[N];
int h[N];
int num[N];
int read(){
    int x=0,w=1;
    char ch=getchar();
    for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*w;
}
bool cmp(st x,st y){return x.val<y.val;}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        line[i].u=read(),line[i].v=read(),line[i].val=read();
    }
    cnt=m;
    //sort(edge+1,edge+m+1,cmp);
    /*for(int i=1;i<=m;i++){
        if(p[edge[i].u]&&p[edge[i].v])continue;
        line[++cnt]=edge[i];
        p[edge[i].u]=true,p[edge[i].v]=true;
    }*/
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            st s;
            s.u=i+n,s.v=j;
            a[i][j]=read();
            s.val=a[i][j];
            line[++cnt]=s;
        }
    }
    for(int i=1;i<=n+k;i++){bcj[i]=i;h[i]=1;}
        sort(line+1,line+cnt+1,cmp);
        for(int i=1;i<=cnt;i++){
            int x=line[i].u,y=line[i].v;
            while(x!=bcj[x])x=bcj[x];
            while(y!=bcj[y])y=bcj[y];
            if(x!=y){
                if(line[i].u>n)bo[line[i].u-n][line[i].v]=true,num[line[i].u-n]++;
                ans+=line[i].val;
                if(h[x]>h[y])swap(x,y);
                bcj[y]=x;
                h[x]=max(h[x],h[y]+1);
            }
        }
        for(int i=1;i<=k;i++){
            if(num[i]!=1)continue;
            for(int j=1;j<=n;j++){
                if(bo[i][j])ans-=a[i][j];
            }
        }
    cout<<ans<<endl;
    return 0;
}
