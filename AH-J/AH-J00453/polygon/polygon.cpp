#include<bits/stdc++.h>
#define P 998244353
using namespace std;
int n,a[5010],g;
long long t[5010][5010];
long long ans;
void init(){
    t[0][0]=1;
    for(int i=1;i<=n;i++){
        t[i][0]=t[i][i]=1;
        for(int j=1;j<i;j++)
            t[i][j]=(t[i-1][j-1]+t[i-1][j])%P;
    }
}
bool cmp(int x,int y){
    return x>y;
}
void dfs(int k,int f,int cnt){
    if(k>2*g && cnt>=3){
        for(int i=f;i<=n;i++)
            ans=(ans+t[n-f][i-f])%P;
        return;
    }
    if(f==n)
        return;
    for(int i=f+1;i<=n;i++)
        dfs(k+a[i],i,cnt+1);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    init();
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(g=1;g<=n;g++){
        dfs(a[g],g,1);
    }
    cout<<ans<<endl;
    return 0;
}
