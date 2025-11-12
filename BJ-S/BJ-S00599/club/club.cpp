#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int n,T,ans=0;
int a[N];
int dp[35][20][20];
priority_queue<pair<int,int>>    q;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>a[i]>>x>>x;
        }
        sort(a+1,a+1+n);
        for(int i=n;i>n/2;i--){
            ans+=a[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
