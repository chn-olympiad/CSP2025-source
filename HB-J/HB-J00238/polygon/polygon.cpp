#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],book[N],p[N];
long long ans;
void dfs(int x,int start,int sum){
    if(x>sum){
        int num=0,maxn=-1e9;
        for(int i=1;i<=sum;i++){
            num+=p[i];
            maxn=max(maxn,p[i]);
        }
        cout<<num<<" "<<maxn<<endl;
        if(num>maxn*2){
            ans++;
        }
        ans%=998244353;
        return;
    }
    for(int i=start;i<=n;i++){
        if(!book[i]){
            p[x]=a[i];
            book[i]=1;
            dfs(x+1,i,sum);
            p[x]=0;
            book[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++){
        dfs(1,1,i);
    }
    cout<<ans%998244353;
    return 0;
}
