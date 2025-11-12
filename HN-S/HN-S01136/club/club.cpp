#include<bits/stdc++.h>
#define reg register
#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define il inline
using namespace std;
il int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9')f=(ch=='-'?-1:f),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
    return x*f;
}
const int N=1e5+5;
int n,a[N][5],mx[N],mxx[N];
priority_queue<pi,vector<pi >,greater<pi > >q[5];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();while(T--){
        n=read();
        for(reg int i=1;i<=n;i++)
            for(reg int j=1;j<=3;j++)
                a[i][j]=read();
        for(reg int i=1;i<=3;i++)
            while(!q[i].empty())
                q[i].pop();
        int ans=0;
        for(reg int i=1;i<=n;i++){
            mx[i]=1;
            for(reg int j=1;j<=3;j++)
                if(a[i][j]>a[i][mx[i]])
                    mx[i]=j;
            mxx[i]=(mx[i]==1?2:1);
            for(reg int j=1;j<=3;j++)
                if(j!=mx[i]&&a[i][j]>a[i][mxx[i]])
                    mxx[i]=j;
            if(q[mx[i]].size()<n/2){
                ans+=a[i][mx[i]];
                q[mx[i]].push(mp(a[i][mx[i]]-a[i][mxx[i]],i));
            }else{
                pi pre=q[mx[i]].top();
                int res1=a[i][mx[i]]-pre.first;
                int res2=a[i][mxx[i]];
                if(res1>res2){
                    ans+=res1;
                    q[mx[i]].pop();
                    q[mx[i]].push(mp(a[i][mx[i]]-a[i][mxx[i]],i));
                    q[mxx[pre.second]].push(mp(0,pre.second));
                }else{
                    ans+=res2;
                    q[mxx[i]].push(mp(0,i));
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

