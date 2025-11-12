#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
#define ll long long
int a[maxn],s[maxn],vis[maxn];
struct node{
    int l,r;
    int n;
}v[maxn];
bool cmp(node a,node b){
    if(a.n==b.n)return true;
    else return a.n<b.n;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    cin>>a[1];
    s[1]=a[1];
    if(a[1]==k){
        vis[1]=1;ans++;
    }
    for(int i=2;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        if(a[i]==k){
            vis[i]=1;ans++;
        }
    }
    ll t=1;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(i==1){
                if(s[j]==k){
                    v[t]=(node){1,j,j};
                    t++;
                }
            }
            else if(s[j]^s[i-1]==k){
                v[t]=(node){i,j,j-i+1};
                t++;
            }
        }
    }
    t--;
    sort(v+1,v+t+1,cmp);
    for(int i=1;i<=t;i++){
        int f=0;
        for(int j=v[i].l;j<=v[i].r;j++){
            if(vis[j]==1){
                f=1;
                break;
            }
        }
        if(f==0){
            for(int j=v[i].l;j<=v[i].r;j++)vis[j]=1;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
