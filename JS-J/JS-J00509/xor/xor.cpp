#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=(1<<20)+5;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
int n,k,s[N],ans,a[N],p[M],lstr;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
    for(int i=1;i<=n;i++){
        p[s[i]^s[lstr]]=i;
        if((p[s[i]^s[lstr]^k]>lstr&&p[s[i]^s[lstr]^k]<i)||(s[i]^s[lstr])==k) ans++,lstr=i;
    }
    cout<<ans<<'\n';
    return 0;
}