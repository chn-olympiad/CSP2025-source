#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,sum=1,ans=0,c[510],nn;string s;
void slove(deque<int>q){
    int d=0;
    for(int a=1;a<=n;a++){int i=q.front();q.pop_front();if(s[a-1]=='0'||d>=c[i]){d=d+1;}}
    if(n-d>=m)ans++;
}
void dfs(int d,deque<int>v1,deque<int>v2){
    //cout<<d<<'\n';
    //for(auto x:v1)cout<<x<<' ';
    //cout<<'\n';
    if(d==n+1){slove(v1);return;}
    for(int i=1;i<=n-d+1;i++){
        v1.push_back(v2.front());v2.pop_front();
        dfs(d+1,v1,v2);
        v2.push_back(v1.back());v1.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;nn=n;
    deque<int>v1,v2;
    //cout<<s<<'\n';
    for(int i=1;i<=n;i++){cin>>c[i];v2.push_back(i);if(c==0)nn--;}
    if(n<=18){
        dfs(1,v1,v2);
        cout<<ans%mod;
        return 0;
    }
    for(int i=1;i<=n;i++)sum=((sum%mod)*(n%mod))%mod;
    if(nn!=0)cout<<sum;
    else cout<<0;
    return 0;
}
