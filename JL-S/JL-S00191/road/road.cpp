#include <bits/stdc++.h>
using namespace std;

const int N=2e6+10;

int n,m,k;
struct node {
    int x,y,z;
} a[N];
int father[N];

int Find(int x){
    if(father[x]==x) return x;
    else return father[x]=Find(father[x]);
}

void link(int x,int y){
    int a=Find(x),b=Find(y);
    father[a]=b;
}

bool check1(){
    if(k!=0) return 0;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    long long ans=0;
    sort(a+1,a+1+m,[](node n,node m){
        return n.z<m.z;
    });
    for(int i=1;i<=m;i++){
        if(Find(a[i].x)!=Find(a[i].y)){
            ans+=a[i].z;
            link(a[i].x,a[i].y);
        }
    }
    cout<<ans;
    return 1;
}

int read(){
    int D;
    char ch;
    int flag=1;
    while(!isdigit(ch=getchar_unlocked())) if(ch=='-') flag=-1;
    for(D=ch-'0';isdigit(ch=getchar_unlocked());){
        D=(D<<3)+(D<<1)+(ch-'0');
    }
    return D*flag;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n=read(); m=read(); k=read();
    if(check1()) return 0;
    for(int i=1;i<=m;i++){
        a[i].x=read();
        a[i].y=read();
        a[i].z=read();
    }
    for(int i=1;i<=k;i++){
        int x;
        x=read();
        int temp[N];
        for(int j=1;j<=n;j++){
            temp[j]=read();
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j!=k){
                    a[++m]={j,k,temp[j]+temp[k]};
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    long long ans=0;
    sort(a+1,a+1+m,[](node n,node m){
        return n.z<m.z;
    });
    for(int i=1;i<=m;i++){
        if(Find(a[i].x)!=Find(a[i].y)){
            ans+=a[i].z;
            link(a[i].x,a[i].y);
        }
    }
    cout<<ans;
    return 0;
}