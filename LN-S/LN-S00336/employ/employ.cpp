#include<bits/stdc++.h>
using namespace std;
long long a[505],b[505],h,c[505];
bool v[505];
long long n,m,maxx;
void dfs(long long cnt,long long sum){
    if(sum>=m&&cnt==n+1){
        h++;
        return;
    }
    if(cnt==n+1)return;
    for(long long i=1;i<=n;i++){
        if((!v[i])&&b[i]>a[cnt-1]){

            if(c[cnt])sum++;
            v[i]=1;
            dfs(cnt+1,sum);
            v[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(m>n)cout<<0;
    for(long long i=1;i<=n;i++){
        char x;
        cin>>x;
        c[i]=x-'0';
        if((x-'0')==0)a[i]=1;
        a[i]=a[i-1]+a[i];

    }
    for(long long i=1;i<=n;i++){
        cin>>b[i];
    }
    dfs(1,0);
    cout<<h;
    return 0;
}
