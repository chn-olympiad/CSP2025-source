#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000001];
bool vis[1000001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    int x=0,y=0;//x cun 0 , y cun 1
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1&&a[i-1]==1&&vis[i]==false&&vis[i-1]==false){
            y++;
            vis[i]=true;
            vis[i-1]=true;
        }
        if(a[i]==0) x++;
    }
    if(k==0){
        cout<<y+x;
        return 0;
    }
    if(k==1){
        cout<<n-x;
        return 0;
    }
    return 0;
}
