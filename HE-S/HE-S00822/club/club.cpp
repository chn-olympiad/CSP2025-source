#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+10;
int n,siz[4],b[N],a[N][4],ans;
inline int in(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') k=(k<<3)+(k<<1)+c-'0',c=getchar();
    return k*f;
}
void slove(){
    n=in();
    siz[1]=siz[2]=siz[3]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=3;j++)
    a[i][j]=in();
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int mx=max({a[i][1],a[i][2],a[i][3]});
        if(a[i][1]==mx) b[i]=1,siz[1]++;
        else if(a[i][2]==mx) b[i]=2,siz[2]++;
        else b[i]=3,siz[3]++;
        ans+=a[i][b[i]];
    }
    int mxn=0;
    if(siz[1]>n/2) mxn=1;
    else if(siz[2]>n/2) mxn=2;
    else if(siz[3]>n/2) mxn=3;
    if(mxn==0)
    {
        printf("%d\n",ans);
        return;
    }
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=mxn) continue;
        int mx1=0;
        if(mxn==1) mx1=max(a[i][2],a[i][3]); 
        else if(mxn==2) mx1=max(a[i][1],a[i][3]); 
        else mx1=max(a[i][1],a[i][2]);
        q.push(a[i][b[i]]-mx1); 
    }
    int ci=q.size()-n/2;
    while(ci)
    {
        ans-=q.top();
        q.pop();
        ci--;
    }
    printf("%d\n",ans);
}
signed main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int T=in();
    while(T--)
    slove();
    return 0;
}