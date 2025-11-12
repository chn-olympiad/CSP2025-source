#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n;
int a[N];
long long cnt=0;
int p[N];
long long sum=0;
void dfs(int pos,int m){
    if(pos>n){
        int maxn=0;
        for(int i=0;i<=n;i++){
            if(p[i]==1){
                sum+=a[i];
                maxn=max(maxn,a[i]);
            }
        }
        if(sum>maxn*2){
            cnt++;
        }
        sum=0;
        return ;
    }
    p[pos]=0;
    dfs(pos+1,m);

    p[pos]=1;
    dfs(pos+1,m);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,n);
    cout<<cnt;

    return 0;
}
