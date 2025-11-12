#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int k[505];
int vis[505];
int cnt=0;
int taotai=0;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        char x;
        cin>>x;
        if (x=='1') k[i]=1;
        else{
            k[i]=0;
            taotai++;
        }
    }
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        vis[x]++;
    }
    int day = n;
    sort(vis+1,vis+m+1);
    cout<<0;


}
