#include<bits/stdc++.h>
using namespace std;
long long ans=0,n;
const int maxn=5e3+5;
long long a[maxn],u[maxn];
bool vis[maxn];
long long sum=0,permax;
priority_queue<long long,vector<long long> >q;
queue<long long>tmp;
long long test;
string s[maxn],stmp;
void dfs(long long num,long long val){
    if(num==n+1)return ;
    if(val==num+1){
        stmp="";sum=0;
        for(long long i=1;i<=val;i++){
            if(u[i]==0)continue;
            q.push(u[i]);
        }
        permax=2*q.top();
        while(!q.empty()){
            if(q.top()==test){
                q.pop();
                continue;
            }
            else{
                test=q.top();
                stmp+=test+'0';
                sum+=q.top();
                q.pop();
            }
        }
        for(long long i=1;i<=ans;i++){
            if(s[i]==stmp){
                return ;
            }
        }
        if(sum>permax and stmp.size()>=3){
            ans++;s[ans]=stmp;
            return ;
        }
    }
    for(long long i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        u[val]=a[i];
        dfs(num,val+1);
        u[val]=0;
        vis[i]=0;
    }
    while(!q.empty()){
        q.pop();
    }
    dfs(num+1,1);
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i];
    dfs(3,1);
    cout<<ans%998244353;
    return 0;
}
