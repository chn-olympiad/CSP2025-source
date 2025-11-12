#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=5005;
int a[N];
int n;
//int ans[N];
int cnt=0;
map<int,int> f[5002];
int C(int n,int m){
    int k=n-m;
    if(f[n][min(m,k)]!=0){
        return f[n][min(k,m)];
    }
    if(n<m)return 0;
    if(n==m)return 1;
    if(m==1)return n;
    if(m==0)return 1;
    return f[n][min(m,k)]=(C(n-1,m-1)%MOD+C(n-1,m)%MOD)%MOD;
}
void dfs(int now,int x,int tar){
    if(now>n)return;
    if(x==2){
        for(int i=now+1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]+a[j]>=tar){
                    //cout<<a[now]<<" "<<a[i]<<" "<<a[j]<<" "<<cnt<<" ";
                    for(int k=0;k<=n-j;k++){
                        cnt+=C(n-j,k);
                        //if(a[now]==98&&a[i]==90&&a[j]==90){
                        //    cout<<C(n-j,k)<<endl;
                        //}
                        cnt%=MOD;
                    }
                    //cout<<cnt<<"\n";
                }
                else{
                    for(int k=j+1;k<=n;k++){
                        //cout<<a[now]<<" "<<a[i]<<" "<<a[j]<<" "<<k<<" "<<a[k]<<" "<<tar-a[i]-a[j]<<"\n";
                        dfs(k,1,tar-a[i]-a[j]);
                    }
                }
            }
        }
    }else{
        for(int i=now;i<=n;i++){
            if(a[i]>=tar){
                for(int k=0;k<=n-i;k++){
                    cnt+=C(n-i,k);
                    cnt%=MOD;
                }
            }else{
                for(int k=i+1;k<=n;k++){
                    dfs(k,1,tar-a[i]);
                }
            }
        }
    }
}
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1,cmp);
    int tar;
    for(int i=1;i<=n-2;i++){
        tar=a[i]+1;
        dfs(i,2,tar);
    }cout<<cnt;
    return 0;
}
