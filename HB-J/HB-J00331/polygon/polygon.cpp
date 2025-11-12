#include<bits/stdc++.h>
using namespace std;
//mark greatest ZhuYunFan;
const int N=998244353;
int n,a[5005],ans,ma,len,siz;
void dfs(int x,int ma){
    if(x>n)return ;
    int mm=max(ma,a[x]);
    len+=a[x];siz+=1;
    if(len>mm*2&&siz>=3)ans++,ans%=N;
//    printf("%d\n",len>ma*2&&siz>=2);
    for(int j=x+1;j<=n;j++){
        dfs(j,mm);
    }
    siz-=1;len-=a[x];
    return ;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",a[i]);
    }
    for(int i=1;i<=n;i++){
        ma=-1,len=0,siz=0;
        dfs(i,ma);
    }
    cout<<ans;
    return 0;
}
