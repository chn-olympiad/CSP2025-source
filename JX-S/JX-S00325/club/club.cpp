#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
const int N=1e5+10;
ll e[10];
bool o[N];
struct Node{
    ll a,b,c,ss;
};
Node w[N];
ll x=0;
void dfs(ll dq,ll f,ll s,ll t,ll z){
    if(dq==n+1){
        x=max(x,z);
        //cout<<z<<" "<<1<<endl;
        return;
    }
    if(f<n/2) dfs(dq+1,f+1,s,t,z+w[dq].a);
    if(s<n/2) dfs(dq+1,f,s+1,t,z+w[dq].b);
    if(t<n/2) dfs(dq+1,f,s,t+1,z+w[dq].c);
}
bool cmp(Node x,Node y){
    return x.a>y.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
      x=0;
      cin>>n;
       for(int i=1;i<=n;i++){
        cin>>w[i].a>>w[i].b>>w[i].c;
       }
       if(n<=30){
            //cout<<n<<endl;
       dfs(1,0,0,0,0);
       //cout<<x<<endl;
       }
       else {
            sort(w+1,w+n+1,cmp);
        for(int i=1;i<=n/2;i++) x+=w[i].a;
       }
       cout<<x<<endl;
    }
    return 0;
}
