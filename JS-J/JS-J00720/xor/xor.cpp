#include<bits/stdc++.h>
using namespace std;
int n,k,xl[500005],s=0;
bool vis[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>xl[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x=0,flag=0;
            for(int a=i;a<=j;a++){
                if(vis[a]){
                    x=k+1;
                    break;
                    //flag=1;
                }
                x=int(x^xl[a]);
            }
            //if(flag==1)continue;
            if(x==k){
                s++;
                for(int a=i;a<=j;a++)vis[a]=true;
            }
        }
    }
    cout<<s;
    return 0;
}
