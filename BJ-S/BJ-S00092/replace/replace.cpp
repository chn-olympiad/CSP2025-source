#include <iostream>
using namespace std;
typedef long long ll;
const int N=200005;
int n, q;
string x[N], y[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    while(q--){
        string s, t;
        cin>>s>>t;
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll p=0;
            while(1){
                ll tmp=s.find(x[i],p);
                if(tmp==-1) break;
                p=tmp+1;
                string sa=s;
                sa.replace(tmp,x[i].length(),y[i]);
                if(sa==t) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}