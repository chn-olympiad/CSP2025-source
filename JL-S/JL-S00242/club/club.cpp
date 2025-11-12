#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;

struct node{
    ll a,b,c;
    ll max_diff;
    char tp;
}v[N];

bool cmp(node x,node y){
    if(x.max_diff!=y.max_diff) return x.max_diff>y.max_diff;
    if(x.a!=y.a) return x.a>y.a;
    if(x.b!=y.b) return x.b>y.b;
    return x.c>y.c;
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].a>>v[i].b>>v[i].c;
        ll da=min(v[i].a-v[i].b,v[i].a-v[i].c);
        ll db=min(v[i].b-v[i].c,v[i].b-v[i].a);
        ll dc=min(v[i].c-v[i].a,v[i].c-v[i].b);
        v[i].max_diff=max(da,max(db,dc));

        if(v[i].max_diff==da) v[i].tp='a';
        else if(v[i].max_diff==db) v[i].tp='b';
        else v[i].tp='c';
    }
    ll cnta=0,cntb=0,cntc=0;
    ll sum=0;
    sort(v+1,v+1+n,cmp);
    for(int i=1;i<=n;i++){
        bool cd=0;
        if(v[i].tp=='a'){
            if(cnta+1<=n/2){
                cnta++;
                sum+=v[i].a;
            }else{
                if(v[i].b>v[i].c){
                    if(cntb+1<=n/2){
                        cntb++;
                        sum+=v[i].b;
                    }else{
                        cntc++;
                        sum+=v[i].c;
                    }
                }else{
                    if(cntc+1<=n/2){
                        cntc++;
                        sum+=v[i].c;
                    }else{
                        cntb++;
                        sum+=v[i].b;
                    }
                }
            }
        }
        if(v[i].tp=='b'){
            if(cntb+1<=n/2){
                cntb++;
                sum+=v[i].b;
            }else{
                if(v[i].a>v[i].c){
                    if(cnta+1<=n/2){
                        cnta++;
                        sum+=v[i].a;
                    }else{
                        cntc++;
                        sum+=v[i].c;
                    }
                }else{
                    if(cntc+1<=n/2){
                        cntc++;
                        sum+=v[i].c;
                    }else{
                        cnta++;
                        sum+=v[i].a;
                    }
                }
            }
        }
        if(v[i].tp=='c'){
            if(cntc+1<=n/2){
                cntc++;
                sum+=v[i].c;
            }else{
                if(v[i].a>v[i].b){
                    if(cnta+1<=n/2){
                        cnta++;
                        sum+=v[i].a;
                    }else{
                        cntb++;
                        sum+=v[i].b;
                    }
                }else{
                    if(cntb+1<=n/2){
                        cntb++;
                        sum+=v[i].b;
                    }else{
                        cnta++;
                        sum+=v[i].a;
                    }
                }
            }
        }
    }
    cout<<sum<<'\n';
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
