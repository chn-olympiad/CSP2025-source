#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=510,M=998244353;
ll n,m,c[N],v[N],g,A,jc[N],cj[N];char s[N];
ll R(){ll a=0;char c=getchar();while(c<48)c=getchar();
    while(c>47)a=(a<<3)+(a<<1)+(c^48),c=getchar();return a;
}
ll ny(ll x){ll a=1;for(int y=M-2;y;y>>=1,x=x*x%M)if(y&1)a=a*x%M;return a;}
void ss(int x,int y){if(y>=m){A+=jc[n-x];if(A>=M)A-=M;return;}
    if(x==n)return;
    for(int i=1;i<=n;i++)if(!v[i]){v[i]=1;
        ss(x+1,y+(s[x]=='1'&&c[i]>x-y));v[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=R(),m=R();scanf("%s",s);for(int i=1;i<=n;i++)c[i]=R();
    for(int i=0;i<n;i++)if(s[i])g++;if(g<m){puts("0");return 0;}
    for(int i=jc[0]=1;i<N;i++)jc[i]=jc[i-1]*i%M;
    cj[N-1]=ny(jc[N-1]);
    for(int i=N-1;i;i--)cj[i-1]=cj[i]*i%M;
    if(m==n){
        for(int i=1;i<=n;i++)if(!c[i]){puts("0");return 0;}
        printf("%lld\n",jc[n]);return 0;
    }ss(0,0);printf("%lld\n",A);
    return 0;
}/*
17:49-18:10
21min 12pts
*/