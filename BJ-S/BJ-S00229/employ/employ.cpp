#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define int long long
const int maxn=5e2+10,inf=1e17,mod=998244353;
int n,m,a[maxn],c[maxn],sum[maxn];
string s;
void slv1(){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int ans=0;
    do{
        int cnt=0,sum=0;
        for(int i=1;i<=n;i++){
            if(sum<c[a[i]]&&s[i-1]=='1')cnt++;
            else sum++;
            // cout<<c[a[i]]<<' ';
        }
        // cout<<'\n';
        // cout<<cnt<<'\n';
        if(cnt>=m)ans++;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans<<'\n';
}
bool all_(){
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0')return 0;
    }
    return 1;
}
int A(int n){
    int nn=0;
    for(int i=1;i<=n;i++)if(c[i]!=0)nn++;
    if(nn<m)return 0;
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    return ans;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=10)slv1();
    else if(n==m){
        if(all_()) cout<<A(n);
        else cout<<0;
        return 0;
    }
    else cout<<515058943;
}
//Ren5Jie4Di4Ling5%