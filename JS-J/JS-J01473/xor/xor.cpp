#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N];
ll xorsum[N];
struct node{
    int first,second;
    bool operator <(const node &x)const{
        return (first-second)<(x.first-x.second);
    }
};
priority_queue<node> q;
bool vis[N];

int main(){
    freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    ll k;
    cin>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xorsum[i]=(a[i]^xorsum[i]);

    }

    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
                if(l==r&&a[l]==k){
                    q.push({l,l});
                }
            if(l!=r&&(xorsum[l]^xorsum[r])==k){
                q.push({l,r});
            }
        }
    }
    int cnt=0;
    while(!q.empty()){
        bool flag=0;
        for(int i=q.top().first;i<=q.top().second;i++){
            if(vis[i]){
                flag=1;
            }
        }
        if(flag==0){
            for(int i=q.top().first;i<=q.top().second;i++){
                vis[i]=1;
            }
            cnt++;
        }
        q.pop();
    }
    cout<<cnt;
    return 0;
}
