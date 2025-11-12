#include<bits/stdc++.h>
#define int long long
#define fors(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+500;
int n,k;
int a[N],d[N];
unordered_map<int,set<int> >mp;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fors(i,1,n){
        cin>>a[i];
        d[i]=(a[i]^d[i-1]);
        mp[d[i]].insert(i);
    }
    int lt=1,ans=0;
    fors(i,1,n){
        int u=(k^d[i]);
        if(mp.count(u)){
            int up=*mp[u].begin();
            int dp=*mp[u].rbegin();
            if(dp>=i-1&&up<=lt-1){
                lt=i+1;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
