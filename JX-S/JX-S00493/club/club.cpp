
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector<int>
#define vl vector<long long>
const int N=1e5+10;
int tt;
struct peo{
    int a,b,c,idx;
}t[N];
bool cmp(peo x,peo y){
    int ab1=x.a-x.b,bc1=x.b-x.c,ac1=x.a-x.c;
    int ab2=y.a-y.b,bc2=y.b-y.c,ac2=y.a-y.c;
    int abc1=ab1,abc2=ab2;
    if(ab1>bc1&&ab1>ac1){abc1=ab1;x.idx=1;}
    else if(bc1>ab1&&bc1>ac1){abc1=bc1;x.idx=2;}
    else if(ac1>ab1&&ac1>bc1){abc1=ac1;x.idx=3;}
    if(ab2>bc2&&ab2>ac2){abc2=ab2;y.idx=1;}
    else if(bc2>ab2&&bc2>ac2){abc2=bc2;y.idx=2;}
    else if(ac2>ab2&&ac2>bc2){abc2=ac2;y.idx=3;}
    return abc1>abc2;
}
int main(){
    freopen("club.in","r",stdin);//please open it
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>tt;
    while(tt--){
        memset(t,0,sizeof t);
        int a1=0,b1=0,c1=0;
        int n;
        cin>>n;
        int n2=n/2;
        for(int i=1;i<=n;i++){
            cin>>t[i].a>>t[i].b>>t[i].c;
        }
        sort(t+1,t+n+1,cmp);
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(a1>=n2)t[i].a=-20005;
            if(b1>=n2)t[i].b=-20005;
            if(c1>=n2)t[i].c=-20005;
            int maxn=max(t[i].a,max(t[i].b,t[i].c));
            ans+=maxn;
            if(t[i].a>t[i].b&&t[i].a>t[i].c)a1++;
            if(t[i].b>t[i].a&&t[i].b>t[i].c)b1++;
            if(t[i].c>t[i].a&&t[i].c>t[i].b)c1++;
            if(t[i].a==t[i].b&&t[i].a==t[i].c)a1++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
