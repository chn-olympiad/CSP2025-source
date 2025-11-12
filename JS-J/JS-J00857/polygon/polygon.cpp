#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],cnt=0;
ll l=1,r=1;
ll number=0;
void dfs(ll i,ll num,ll maxn,ll cnt){
    if(i>=n){
        number+=cnt;
        return ;
    }
    if(num>2*maxn){
        cnt++;
    }
    dfs(i+1,num+a[i],max(maxn,a[i]),cnt);
    dfs(i+1,num,maxn,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<number;
    // while(1){
    //     ll number=0;
    //     ll maxn=0;
    //     for(ll i=l;i<=r;i++){
    //         number+=a[i];
    //         maxn=max(maxn,a[i]);
    //     }
    //     if(number>2*maxn){
    //         cnt++;
    //         cout<<l<<" "<<r<<endl;
    //     }
    //     if(r==n){
    //         l++;
    //         r=l;
    //     }else{
    //         r++;
    //     }
    //     if(l>n&&r>n){
    //         cout<<cnt<<endl;
    //         return 0;
    //     }
    // }
    return 0;
}