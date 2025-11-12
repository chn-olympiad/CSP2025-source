#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define f(i,a,b) for(int i=a;i<b;++i)
#define f2(i,a,b) for(int i=a;i<=b;++i)
#define LEN(x) (int)x.size()
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
string s;
vector<int> a;
bool cmp(int t1,int t2){
    return t1>t2;
}
void solve();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
void solve(){
    a.clear();
    cin>>s;
    f(i,0,LEN(s)){
        if(s[i]<'0'||s[i]>'9') continue;
        int c=(s[i]-'0');
        a.push_back(c);
    }
    sort(a.begin(),a.end(),cmp);
    if(a[0]==0) cout<<0;
    else f(i,0,LEN(a)) cout<<a[i];
    cout<<endl;
}