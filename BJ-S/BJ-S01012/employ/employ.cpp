#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,P=998244353;
char s[N];
int c[N];
ll ans;
int n,m;
int vis[N];
void dfs(int step,int no,int yes){
    //cout<<step<<" "<<no<<" "<<yes<<endl;
    if(n-no<m) return;
    if(step>n){
        if(yes>=m){
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        if(s[step]=='1'){
            if(c[i]>no){
                vis[i]=1;
                dfs(step+1,no,yes+1);
                vis[i]=0;
            }else{
                vis[i]=1;
                dfs(step+1,no+1,yes);
                vis[i]=0;
            }
        }else{
            vis[i]=1;
            dfs(step+1,no+1,yes);
            vis[i]=0;
        }

    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool flaga=1;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]=='0'){
            flaga=0;
        }
        //cout<<"s:"<<s[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    /*
    if(flaga){
        //cout<<"A:\n";
        int sr=0;
        for(int i=1;i<=n;i++){
            if(c[i]>0){
                sr++;
            }
        }
        if(m<=sr){
            ll ta=1;
            for(int i=1;i<=sr;i++){
                ta*=i;
                ta%=P;
            }
            cout<<ta;
        }else{
            cout<<0;
        }
        return 0;
    }
    if(m==n){
       ll ta=1;
        ll sum[N];
        sum[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+(s[i]=='1' ? 1 : 0);
        }
        sort(c+1,c+n+1,greater<int>());
        int j=1;
        for(int i=n;i>=1;i--){
            if(c[j]>sum[i]){
                j++;
            }else{

            }
        }
    }
    */
    dfs(1,0,0);
    cout<<ans;
}
