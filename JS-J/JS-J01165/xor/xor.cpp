#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
long long cnt=0;
bool vis[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            cnt++;
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            int xr=a[i];
            for(int j=i+1;j<=n;j++){
                if(vis[j]==0){
                    xr^=a[j];
                }else break;
                if(xr==k){
                    //cout<<i<<" "<<j<<endl;
                    cnt++;
                    i=j+1;
                    xr=a[i];
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
