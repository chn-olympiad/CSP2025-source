#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
string s;
int c[N];
int a[N];
bitset<N> v;
int n,m,ans=0;
void dfs(int x,int sum){
    if(x>n){
        if(n-sum>=m){
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            a[x]=i;
            if(c[i]<=sum||s[x]=='0'){
                dfs(x+1,sum+1);
            }
            else{
                dfs(x+1,sum);
            }
            v[i]=0;
        }
    }
}
signed main(){
     freopen("employ.in","r",stdin);
     freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
