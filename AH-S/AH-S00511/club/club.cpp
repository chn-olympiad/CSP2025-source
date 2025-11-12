#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
int T,n,ans;
int a[N],b[N],c[N];
struct Node{
    int value,pos;
}x[4];
struct nod{
    int value,pos;
    bool operator < (const nod &x) const{
        return value>x.value;
    }
};
bool flag[N][4];
bool cmp(const Node &x,const Node &y){
    return x.value>y.value;
}
int cnt=0;
void dfs(int temp,int sum1,int sum2,int sum3,int ans){
    if(temp>n) cnt=max(cnt,ans);
    if(sum1<n/2) dfs(temp+1,sum1+1,sum2,sum3,ans+a[temp]);
    if(sum2<n/2) dfs(temp+1,sum1,sum2+1,sum3,ans+b[temp]);
    if(sum3<n/2) dfs(temp+1,sum1,sum2,sum3+1,ans+c[temp]);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%d",&T);
    while(T--){
        cnt=0;
        scanf("%d",&n);
        for(int k=1;k<=n;k++)
                scanf("%d%d%d",&a[k],&b[k],&c[k]);
        dfs(1,0,0,0,0);


        printf("%d\n",cnt);
    }
}
