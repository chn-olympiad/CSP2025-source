#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],f[505],t[505],l[505],cnt;
char x;
bool c[505];
long long dfs(int k,int h){
    if(k==n+1){
        if(n-h>=m) return 1;
        return 0;
    }
    f[k+1]=f[k];
    long long sum=0;
    if(c[k]==0){
        for(int i=1;i<=n;i++){
            if(a[i]>=f[k+1]&&!t[i]){
                t[i]=1;
                l[a[i]]--;
                int cnt1=cnt;
                cnt++;
                for(int j=cnt;j<=cnt;j++){
                    f[k+1]+=l[j];
                    cnt+=l[j];
                }
                sum+=dfs(k+1,h+1);
                cnt=cnt1;
                f[k+1]=0;
                l[a[i]]++;
                t[i]=0;
            }
        }
        return sum%998244353;
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=f[k+1]&&!t[i]){
            t[i]=1;
            sum+=dfs(k+1,h);
            t[i]=0;
        }
    }
    return sum%998244353;
}
int main(){
    freopen("empty.in","r",stdin);
    freopen("empty.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        c[i]=x-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]]++;
    }
    cnt=l[0];
    cout<<dfs(1,0);
    return 0;
}
