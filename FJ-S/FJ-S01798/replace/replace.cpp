#include<bits/stdc++.h>
using namespace std;const int N=2e5+5,M=1e7+5;
int n,m,ei=4,Ei=1,h[M],H[M],f[M],e[M],ans;bitset<N>A,B;
struct P{int n,t;}E[N<<2];char g[M];string p,q,a,b,x,y;
void ad(int x,string a,int l){
    for(int i=0,A=a.size(),t;i<A;i++){t=-1;
        for(int j=h[x];j;j=e[j])if(g[j]==a[i])t=j,j=0;
        if(t==-1)e[ei]=h[x],g[ei]=a[i],t=h[x]=ei++;x=t;
    }E[Ei]={H[x],l},H[x]=Ei++;
}
void fd(int x,string a){int y=x;
    for(int i=0,A=a.size(),t;i<A;i++){t=-1;
        if(y>1)for(int j=H[x];j;j=E[j].n)B[E[j].t]=1;
        for(int j=h[x];j;j=e[j])if(g[j]==a[i])t=j,j=0;
        if(t==-1)i=A,y=-1;x=t;
    }if(y>1)for(int j=H[x];j;j=E[j].n)B[E[j].t]=1;
    if(y<2&&~y)for(int j=H[x];j;j=E[j].n)B[E[j].t]=1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){a="",b="",x="",y="";cin>>p>>q;
        int l,r,z=p.size();for(l=0;p[l]==q[l]&&l<z;l++)a=p[l]+a;
        if(l==z)continue;for(r=z-1;p[r]==q[r];r--)b=p[r]+b;
        for(int i=l;i<=r;i++)x=x+p[i],y=y+q[i];
        ad(0,x,i),ad(1,y,i),ad(2,a,i),ad(3,b,i);
    }
    while(m--){a="",b="",x="",y="";cin>>p>>q;
        int l,r,z=p.size();for(l=0;p[l]==q[l];l++)a=p[l]+a;
        for(r=z-1;p[r]==q[r];r--)b=p[r]+b;
        for(int i=l;i<=r;i++)x=x+p[i],y=y+q[i];ans=B=0;fd(0,x);
        A=B;B=0;fd(1,y);A&=B;B=0;fd(2,a);A&=B;B=0;fd(3,b);A&=B;
        for(int i=1;i<=n;i++)if(A[i])ans++;cout<<ans<<endl;
    }return 0;
}/*
15:23-17:49
1h26min 35-70pts
*/