#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INT __int128
#define u_mp unordered_map
#define u_st unordered_set
#define fastrd ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
template<class T>
T read(){
    char c=getchar();
    T a=0;
    bool f=0;
    while(!isdigit(c)){
        if(c=='-'){
            f=1;
        }
        c=getchar();
    }
    while(isdigit(c)){
        a=a*10+(c-'0');
        c=getchar();
    }
    if(f){
        a=-a;
    }
    return a;
}
template<class T>
void print(T a){
    if(a<0){
        putchar('-');
        a=-a;
    }
    if(a<9){
        putchar(char(a+'0'));
        return;
    }
    print(a/10);
    putchar(char(a%10+'0'));
}
int dp[1000005];
int sum[1000005],a[1000005];
u_mp<int,int>mp;
int n,d;
int main(){
    fastrd
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>d;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];

    }
    int maxs=0,maxx=0;
    for(int j=1;j<=n;j++){
        mp[sum[j]]=j+1;
        if(dp[j-1]>maxs){
            maxs=dp[j-1];
            maxx=j-1;
        }
        if(mp[d^sum[j]]==0){
            mp.erase(d^sum[j]);
            continue;
        }
        int i=mp[d^sum[j]]-1;
        if(i>=maxx&&i<j){
            dp[j]=max(dp[j],maxs+1);
        }
    }
    int ans=0;
    for(int j=1;j<=n;j++){
        ans=max(ans,dp[j]);
    }
    cout<<ans;
    return 0;
}
