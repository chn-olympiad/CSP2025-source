#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,k,ans;
ll a[N],sum[N];
//struct Node{
//    int x,y;
//}s[N];
//bool cmp(Node p,Node q){
//    return p.y-p.x>q.y-q.x;
//}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]^a[i]);
    }
    //for(int i=1;i<=n;i++){
    //    cout<<sum[i]<<" ";
    //}
    //cout<<(2^0);
    int cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                //s[cnt].x=i;
                //s[cnt].y=j;
                //cnt++;
                //cout<<i<<" "<<j<<endl;
                i=j;
                ans++;
                continue;
            }
        }
    }
    //sort(s+1,s+1+cnt,cmp);
    //for(int i=1;i<cnt;i++){
    //    if()
        //cout<<s[i].x<<" "<<s[i].y<<endl;
    //}
    cout<<ans;
    return 0;
}
