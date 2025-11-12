#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
int n,k,num,ans,a[N];
inline int sum(int l,int r){
    int res=a[l];
    for(int i=l+1;i<=r;i++){
        res^=a[i];
    }return res;
}void dfs(int x){
    if(x>n){
        ans=max(ans,num);
        return;
    }
    for(int i=x;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(sum(i,j)==k){
                num++;
                dfs(j+1);
                num--;
            }
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }dfs(1);
    printf("%d",ans);
    return 0;
}
