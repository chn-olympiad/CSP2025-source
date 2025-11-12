//115652
#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int mod=998244353;
int n;
int a[maxn];
int qzh[maxn];
int d[maxn];
int ans;
bool visited[maxn]={false};
void dfs(int p){
    visited[p]=true;
    int cnt=0;
    int maxi=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(visited[p]){
            sum++;
            cnt+=a[i];
            maxi=max(maxi,a[i]);
        }
    }
    if(sum>=3&&cnt>2*maxi){
        ans++;
        ans%=mod;
    }
    for(int i=p+1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    visited[p]=false;
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    /*for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        d[i]=2*a[i];
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(j<i+2){
               continue;
            }
            int sum=qzh[j]-qzh[i-1];
            if(sum>d[j]){
                tot++;
            }
        }
    }*/

    for(int i=1;i<=n;i++)
        dfs(i);

    cout<<ans<<endl;
    return 0;
}
