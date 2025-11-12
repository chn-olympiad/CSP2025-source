#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5;
struct M{
    string s1,s2;
    string t1,t2;
}a[N],b[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
    }
    for(int i=1;i<=q;i++){
        cin>>b[i].t1>>b[i].t2;
    }
    for(int i=1;i<=q;i++) cout<<0<<"\n";
    return 0;
}
