#include<bits/stdc++.h>//part pass
using namespace std;
#define int long long

int a[1010101];
int vis[1010101]={false};

signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin>>n>>k;
    bool onecheck=true;
    bool lessonecheck=true;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) onecheck=false;
        if(a[i]>1) lessonecheck=false;
    }

    if(onecheck==true&&k==0){
        cout<<n;
        return 0;
    }

    int cnt=0;

    if(lessonecheck==true){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) cnt++,vis[i]=true;
                if(a[i]==a[i+1]&&a[i]==1&&vis[i]==false&&vis[i+1]==false){
                    cnt++;
                    vis[i]==true;
                    vis[i+1]==true;
                }
            }
            cout<<cnt;
            return 0;
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1) cnt++;
            }
            cout<<cnt;
            return 0;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
