#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=5e5+10;
ll n,k,a[len];
ll dp[len];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for(int i=n;i>=1;i--){
        dp[i]=max(dp[i+1],dp[i]);
        for(int j=i;j<=n;j++){
            if((a[i-1]^a[j])==k){
                dp[i]=max(dp[i],dp[j+1]+1);
            }
        }
    }
    cout<<dp[1];
    return 0;
}
//09:46 finished programming...
// i'm not sure if i can AC this one
// i don't really use queue like this
// humanity psychological abuse of some kind
// never mind, i failed
// ok i've tried to alter some part of it 09:57
// i don't know if building some queue like these would possibly lead my time to be over
// i find a problem in my solution.let's try again
// i give up t4 now, 60 i believe is enough, i'm not capable of ak
// i think i'm confident to get 1= this time???anyway.
// 10:48 and still no clue on the right solution~
// actually i think i can get a little point using this version on special A&B, but i want to AC this one
// pls let 1= be over 200
// I'll spend my last time to it till 11:25,which is 30min,or i'll take baoli
// i'll try baoli by 1e3,which is i believe 60 it can make me 320,too weak for AC[cry face]
// a little pre might lead to AC, but i won't try, if i try,there's a higher possibility for me to just get 0
// it's quite fun that i use dp instead, but i can't solve the dp in t4(never!!)
// why is let's a terorst group in linux's dictionary
// synonyms is FUN!!
// i'll try polygon for the second time. ihave already fenliu so there's no worry
