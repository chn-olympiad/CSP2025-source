#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
int a[500100];
bool vis[500100];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int pp=0,cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            for(int u=i;u<=i+j;u++){

                if(vis[u]==0){
                    pp=pp^a[u];
                }


            }
            if(pp==k){
                cnt++;
                for(int u=i;u<=i+j;u++){
                    vis[u]=1;
                }
            }
            pp=0;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

