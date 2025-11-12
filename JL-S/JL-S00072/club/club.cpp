#include<bits/stdc++.h>
using namespace std;
struct qwq{
    int a1;
    int a2;
    int a3;
};
struct wqw{
    int a1;
    int a2;
};
qwq a[200000];
int n,t,ans,qa,qb,qc;
wqw b[200000],c[200000],d[200000],e[200000],f[200000];
bool aa[200000];
bool qwqw(wqw q,wqw w){
    if(q.a1==w.a1)return q.a2>w.a2;
    return q.a1>w.a1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)b[i].a1=0,b[i].a2=0,c[i].a1=0,c[i].a2=0,d[i].a1=0,d[i].a2=0,e[i].a1=0,e[i].a2=0,f[i].a1=0,f[i].a2=0,a[i].a1=0,a[i].a2=0,a[i].a3=0,aa[i]=0;
        qa=0,qb=0,qc=0,ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            b[i].a1=a[i].a1-max(a[i].a2,a[i].a3);
            c[i].a1=a[i].a2-a[i].a3;
            d[i].a1=a[i].a1-a[i].a2;
            e[i].a1=a[i].a3-max(a[i].a2,a[i].a1);
            f[i].a1=a[i].a2-a[i].a1;
            b[i].a2=i;
            c[i].a2=i;
            d[i].a2=i;
            e[i].a2=i;
            f[i].a2=i;
        }
        sort(b+1,b+n+1,qwqw);
        sort(c+1,c+n+1,qwqw);
        sort(e+1,e+n+1,qwqw);
        sort(d+1,d+n+1,qwqw);
        for(int i=1;i<=n/2;i++){
            if(b[i].a1>0)ans+=a[b[i].a2].a1,aa[b[i].a2]=1,qa++;
        }
        for(int i=1;i<=n&&qb<=n/2;){
            if(c[i].a1>0&&aa[c[i].a2]==0)ans+=a[c[i].a2].a2,aa[c[i].a2]=1,qb++;
            i++;
        }
        for(int i=1;i<=n&&qc<=n/2;){
            if(aa[e[i].a2]==0&&qc!=n/2)ans+=a[e[i].a2].a3,aa[e[i].a2]=1,qc++;
            i++;
        }
        if(qa+qb+qc<n){
            for(int i=1;i<=n&&qa<=n/2;){
                if(d[i].a1>0&&aa[d[i].a2]==0&&qa!=n/2)ans+=a[d[i].a2].a1,aa[d[i].a2]=1,qa++;
                i++;
            }
        }
        if(qa+qb+qc<n){
            for(int i=1;i<=n&&qb<=n/2;){
                if(aa[f[i].a2]==0&&qb!=n/2)ans+=a[f[i].a2].a2,aa[f[i].a2]=1,qb++;
                i++;
            }
        }
        cout<<ans<<endl;
    }
}
