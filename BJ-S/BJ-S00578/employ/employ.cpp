#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
int b[N],c[N];
int n,m;
ll md=998244353;
bool v[N],v2[N];
ll ans=0;
void dfs(int x,ll y){
    if(y>n-m) return ;
    if(x==n+1){
        ans++;
        ans%=md;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(v2[i]) continue;
        v2[i]=1;

        if(b[x]==0||y>=c[i]){
            //cout<<0<<" "<<x<<" "<<i<<" "<<y+1<<endl;
            dfs(x+1,y+1);
        }

        else{
            //cout<<1<<" "<<x<<" "<<i<<" "<<y<<endl;
            dfs(x+1,y);
        }
        v2[i]=0;
    }
}
/*void dfs(int x,int y){
    if(x==n+1){
        ds(1);
        return ;
    }
    v[x]=1;
    dfs(x+1);
    y++;
    if(y>n-m) return ;
    v[x]=0;
}*/
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) b[i]=s[i-1]-'0';
    //for(int i=1;i<=n;i++) b[i]+=b[i-1];
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+1+n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i-b[i]>=c[i]) cnt++;
    }
    if(cnt>m){
        cout<<0;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
