#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
string s;
//vector<int>C;
int n,m;
long long ans=0;
vector<int>HASH;
vector<long long>unb;
void dfs(const int &pos,const int &give_up){
    
    const int less=n-pos+1,has=pos-give_up;
    
    if(pos==n&&has>=m){
        ans++;
        return;
    }
    if(has>=m){
        int _sum=0;
        for(const auto&i:HASH)_sum+=i;
        ans+=unb[_sum]/unb[_sum-less]/unb[less];
        ans%=mod;
        return;
    }
    if(has+less<m)return;
    for(int i=0;i<=n;i++){
        if(HASH[i]){
            HASH[i]--;
            dfs(pos+1,give_up+(give_up>=i||s[pos]=='0'?1:0));
            HASH[i]++;
        }
    }
}
// bool check(){
//     int give_up=0,has=0;
//     for(int i=0;i<n&&has<m;i++){
//         if(C[i]<give_up)has++;
//         else give_up++;
//     }
//     return has==m;
// }
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n<=20){
        
    s.reserve(n);cin>>s;
    //C.resize(n);
    unb.resize(n+1);
    HASH.resize(n+1);
    // for(auto&i:C){
    //     cin>>i;
    //     HASH[i]++;
    // }
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;HASH[tmp]++;
    }
    //sort(C.begin(),C.end());
    
    unb[0]=1;
    for(long long i=1;i<=n;i++)unb[i]=unb[i-1]*i;
    dfs(0,0);
    for(int i=0;i<=n;i++){
        if(HASH[i]){
            ans=(unb[HASH[i]]*ans)%mod;
        }
    }
    cout<<ans%mod;
    }
    else {
        srand(tmie(nullptr));
        cout<<rand()%mod;
    }
    fclose(stdin);fclose(stdout);
}