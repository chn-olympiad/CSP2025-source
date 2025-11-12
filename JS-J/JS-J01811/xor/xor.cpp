#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN(5005);
ll n,k;
ll a[MAXN];
ll pre[MAXN];
bool vis[MAXN];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int sum(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            vis[i]=true;
            sum++;
        }
        pre[i]=pre[i-1]^a[i];
    }
    for(int c=1;c<=n;c++)
        for(int i=1;i<=n;i++){
            int j=i+c;
            if(j>n)break;
            if((pre[i-1]^pre[j])==k){
                bool f=false;
                for(int b=i;b<=j;b++){
                    if(vis[b]){
                        f=true;
                        break;
                    }
                }
                if(!f){
                    for(int b=i;b<=j;b++){
                        vis[b]=true;
                    }
                    sum++;
                }
            }
        }
    cout<<sum;
    return 0;
}
