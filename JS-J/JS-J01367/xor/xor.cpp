#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n,k;
long long cnt = 0;
int a[N+3],b[N+3][N+3];
int vis[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        b[i][i] = a[i];
    }


    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(i != j){
                b[i][j] = b[i][j-1]^a[j];
                //cout<<b[i][j]<<" ";
            }
        }
       // cout<<endl;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(b[i][j] == k && !vis[j]){
                cnt++;
                vis[j] = 1;
               // cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
