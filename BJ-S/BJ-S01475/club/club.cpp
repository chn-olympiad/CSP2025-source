#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
int T,n,ans;
struct node{
    int a,b,c;
    bool vis=0;
}z[N];
bool cmp(node a,node b){
    if(a.a==b.a&&a.b==b.b) return a.c>b.c;
    if(a.a==b.a) return a.b>b.b;
    return a.a>b.a;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        memset(z,0,sizeof z);
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>z[i].a>>z[i].b>>z[i].c;
        }
        sort(z+1,z+1+n,cmp);
        if(z[1].b==0&&z[1].c==0){
            for(int i=1;i<=n/2;i++) ans+=z[i].a;
            cout<<ans<<'\n';
            continue;
        }
        if(z[1].a==0&&z[1].c==0){
            for(int i=1;i<=n/2;i++) ans+=z[i].b;
            cout<<ans<<'\n';
            continue;
        }
        if(z[1].b==0&&z[1].a==0){
            for(int i=1;i<=n/2;i++) ans+=z[i].c;
            cout<<ans<<'\n';
            continue;
        }
        int cnta=0,cntb=0,cntc=0;
        for(int i=n;i>=1;i--){
            node t=z[i];
            int sum=t.a+t.b+t.c,mx=max(t.a,max(t.b,t.c)),mn=min(t.a,min(t.b,t.c));
            if(mx==t.a){
                if(cnta<n/2) ans+=t.a,cnta++;
                else if((sum-mx-mn)==t.b){
                    if(cntb<n/2) ans+=t.b,cntb++;
                    else ans+=t.c,cntc++;
                }
                else {
                    if(cntc<n/2) ans+=t.c,cntc++;
                    else ans+=t.b,cntb++;
                }
            }
            else if(mx==t.b){
                if(cntb<n/2) ans+=t.b,cntb++;
                else if((sum-mx-mn)==t.a){
                    if(cnta<n/2) ans+=t.a,cnta++;
                    else ans+=t.c,cntc++;
                }
                else {
                    if(cntc<n/2) ans+=t.c,cntc++;
                    else ans+=t.a,cnta++;
                }
            }
            else if(mx==t.c){
                if(cntc<n/2) ans+=t.c,cntc++;
                else if((sum-mx-mn)==t.a){
                    if(cnta<n/2) ans+=t.a,cnta++;
                    else ans+=t.b,cntb++;
                }
                else {
                    if(cntb<n/2) ans+=t.b,cntb++;
                    else ans+=t.a,cnta++;
                }
            }

        }
        cout<<ans<<'\n';
    }
    return 0;
}
