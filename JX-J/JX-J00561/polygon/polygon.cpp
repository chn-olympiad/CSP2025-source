#include <bits/stdc++.h>
using namespace std;
int n,z,a[5005];
void dfs(int h,int ma,int depth){
    if (depth>n){
        if(h>ma*2) z++;
        return ;
    }
    dfs(h,ma,depth+1);
    dfs(h+a[depth],max(ma,a[depth]),depth+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(0,0,1);
    cout<<z;
    return 0;
}
