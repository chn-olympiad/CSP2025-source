#include<iostream>
using namespace std;
int n,a[5010],ma=0,g,ans,tim,now;
void dfs(int pos){
    if(pos==n+1){
        for(int i=1;i<=n;i++){
            if(vis[i]){
                ans+=a[i];
                ma=max[ma,a[i]];
                g++;
                if(ans>=ma)

            }
            
        }
        return
    }
    for(int i=0)
}
int main(){

}