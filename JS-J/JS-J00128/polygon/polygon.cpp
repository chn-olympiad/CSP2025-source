#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=998244353;
int n;  
vector<int> a,s;
int ans;
// void solve(int i,int sum,int line,int nl){
//     if(nl==line-1){
//         for(int j=i+1;j<=n-1;j++){
//             if(sum>a[j]){
//                 ans+=(j-i-1)%N;
//                 ans%=N;
//             }
//         }
//     }
//     for(int j=i+1;j<=n-(line-i-1);j++){
    
//        solve(j,sum+=a[j],line,nl+1);
//     }
//     return;
// }
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int b;
        cin>>b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    s.push_back(a[0]);
    for(int i=2;i<=n;i++){
        s.push_back(s[i-2]+a[i-1]);
    }
    for(int i=n-1;i>=2;i--){
        int lft,rgt=i;
        if(a[i]>=s[i-1])continue;
        for(int j=i-1;j>=0;j--){
            if(a[i]>=s[j-1]){
                lft=j;
                break;
            }
        }
        ans=ans%N+(((rgt-1-lft)%N)*(lft%N))%N;
        ans%=N;
    }
    // for(int i=3;i<=n;i++){
    //     solve(-1,0,i,0);
    // }
    cout<<ans;
    return 0;
}