#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1e6+1e5+190;
int read(){
    int f=1,k=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')k=k*10+(c-'0'),c=getchar();
    return f*k;
}

struct edge{
    int x1,x2;
    int w;
};
int fei[N];
bool f[N];
edge num[N];


int fa[N];
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
void unint(int x,int y){
    int roox=find(x);
    int rooy=find(y);
    fa[rooy]=roox;
}

int cmp(edge qw,edge pw){
    return qw.w<pw.w;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n=read(),m=read(),k=read();
    int bian=0;
    for(int i=1;i<=m;i++){
        edge tp;
        bian++;
        tp.x1=read();
        tp.x2=read();
        tp.w=read();
        num[bian]=tp;
    }
    for(int i=1;i<=k;i++){
        fei[i]=read();
        for(int j=1;j<=n;j++){
            bian++;
            edge iuy;
            iuy.x1=n+i;
            iuy.x2=j;
            iuy.w=read()+fei[i];
            num[bian]=iuy;
        }
    }

    sort(num+1,num+bian+1,cmp);

    init(k+n);

    int sum=0;
    int oiu=0,jian=1;
    while(oiu<n){
        edge np=num[jian];
        if(find(np.x1)!=find(np.x2)){
            unint(np.x1,np.x2);
            if(np.x1<=n)oiu++;
            else{
                if(f[np.x1-n]==false)f[np.x1-n]=true;
                else sum-=fei[np.x1-n];
            }
            if(np.x2<=n)oiu++;
            else{
                if(f[np.x2-n]==false)f[np.x2-n]=true;
                else sum-=fei[np.x2-n];
            }
            sum+=np.w;
        }
        jian++;
    }

    cout<<sum;

    return 0;
}

//Z-9
//Zhao
