#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
inline int read(){
    int x=0,w=1;
    char ch=getchar();
    for(;ch<'0'||'9'<ch;ch=getchar())if(ch=='-')w=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())x=10*x+ch-'0';
    return x*w;
}
int n,ans,a[3][N],b[3],c[3][N],d[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        n=read(),ans=b[0]=b[1]=b[2]=0;
        for(int i=1;i<=n;++i)for(int j=0;j<3;++j)a[j][i]=read();
        for(int i=1;i<=n;++i)
            for(int j=0;j<3;++j)if(a[j][i]>=max(a[0][i],max(a[1][i],a[2][i])))
                {ans+=a[j][i],c[j][++b[j]]=i;break;}
        if(b[1]>n/2)swap(a[0],a[1]),swap(c[0],c[1]),swap(b[0],b[1]);
        if(b[2]>n/2)swap(a[0],a[2]),swap(c[0],c[2]),swap(b[0],b[2]);
        if(b[0]>n/2){
            for(int i=1;i<=b[0];++i)d[i]=a[0][c[0][i]]-max(a[1][c[0][i]],a[2][c[0][i]]);
            sort(d+1,d+b[0]+1);
            for(int i=1;i<=b[0]-n/2;++i)ans-=d[i];
        }printf("%d\n",ans);
    }return 0;
}