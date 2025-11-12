#include<bits/stdc++.h>
using namespace std;
const int N=505;
const long long MOD=998244353;
int n,m,q,cnt,a[N],b[N];
bool vis[N];
int success[20];
long long ans;
bool A=true;
string s;
void dfs(int x){
    if(x-1-success[x-1]>n-m) return;
    if(x>n){
        if(success[n]>=m) ans++;
        ans%=MOD;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(x-1-success[x-1]<a[i]&&s[x-1]-'0'==1) success[x]=success[x-1]+1;
        else success[x]=success[x-1];
        vis[i]=true;
        //cout<<x<<" "<<i<<" "<<success[x]<<endl;
        dfs(x+1);
        vis[i]=false;
        //cout<<"back"<<endl;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    q=n;
    for(int i=1;i<=n;i++){
        if(a[i]==0) q--;
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[i+1]=s[i]-'0';
        if(b[i+1]==0) A=false;
        else cnt++;
    }
    //8/100 n<=10, O(n!)
    if(n<=18){
        dfs(1);//day1
        cout<<ans<<endl;
    }
    return 0;
}
