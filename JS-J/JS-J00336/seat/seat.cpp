#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fo(i,v) for(auto i:v)
ll m,n;
struct S{
    ll k,score;
}s[105];
bool operator<(const S& a,const S& b) { return a.score>b.score; }
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    f(i,1,104) s[i].k=i;
    f(i,1,n*m) cin>>s[i].score;
    sort(s+1,s+n*m+1);
    // f(i,1,n*m) clog<<s[i].score<<' '<<s[i].k<<endl;
    ll i=1;
    while(s[i].k!=1) i++;
    ll res1=i/n,res2=i%n;
    if(res2==0) {
        cout<<res1<<' '<<n<<endl;
    } else if(res1%2==1) {
        cout<<res1+1<<' '<<n-res2+1<<endl;
    } else {
        cout<<res1+1<<' '<<res2<<endl;
    }
    clog<<res1<<' '<<i<<' '<<s[i].score;
    return 0;
}
/* Expected Score: 100 */
