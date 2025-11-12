#include<iostream>
using namespace std;
const int N=505;
int n,m,k;
long long ans;
int c[N],s[N];
string a;
bool used[N];
void dfs(int k,int cnt){
    if(k==n){
        //cout<<endl;
        if(n-cnt>=m){
            ans++;
            ans%=998244353;
        //cout<<"###"<<n<<cnt<<m<<endl;
        }
        return;
    }
    if(n-cnt<m){
        //cout<<"*";
        return;
    }
    for(int i=0;i<n;i++){
        if(used[i])continue;
        if(cnt>=c[i])cnt++;
        else if(s[k]==0)cnt++;
        used[i]=1;
        //cout<<i<<endl;
        dfs(k+1,cnt);
        used[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>a;
    for(int i=0;i<a.size();i++){
        s[i]=a[i]-'0';
    }
    for(int i=0;i<n;i++)cin>>c[i];
    dfs(0,0);
    cout<<ans;
    return 0;
}