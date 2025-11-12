#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,c[N],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++) ans+=c[i];
    cout<<ans<<"\n";
    return 0;
}