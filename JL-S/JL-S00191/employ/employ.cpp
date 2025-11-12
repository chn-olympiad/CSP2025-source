#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,m;
int a[N];
string s;
int vis[N];
int ans=0;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vis[i]=i;
    }
    do {
        int leave=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0' || leave>=a[vis[i+1]]){
                leave++;
            } else {
                cnt++;
            }
        }
        if(cnt>=m) {
            ans++;
        }
    } while(next_permutation(vis+1,vis+1+n));
    cout<<ans;
    return 0;
}