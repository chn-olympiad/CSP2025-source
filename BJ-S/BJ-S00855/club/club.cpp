#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=1e5+5;
struct sty{
    LL a;
    LL b;
    LL c;
    LL Max;
};
int main(){
    freopen("club.in","read",iostream);
    freopen("club.ans","write",iostream);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL t;
    LL n;
    LL cnta,cntb,cntc;
    sty p[MAXN];
    cin>>t;
    while(t--){
        cin>>n;
        int cnt=0;
        int cnta=0;
        int cntb=0;
        int cntc=0;
        for(int i=1;i<=n;i++){
            cin>>p[i].a;
            cin>>p[i].b;
            cin>>p[i].c;
            p[i].Max=max(max(p[i].a,p[i].b),p[i].c);
            if(p[i].b==0){
                cnt++;
            }

        }
        if(cnt==n){
            LL ans;
            for(LL i=1;i<=n;i++){
                ans+=p[i].a;
            }
            cout<<ans;
            return 0;
        }

    }
    return 0;

}
