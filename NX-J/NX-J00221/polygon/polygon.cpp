#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n,a[5005],ans=0;

int book[5005];

bool check(int x){
    int maxx=0,sum=0,s=0;
    for(int i=1;i<=n;i++){
        if(book[i]==1){
            s++;

            sum+=a[i];
            maxx=max(maxx,a[i]);
        }
    }
    if(s<3) return 0;
    return 2*maxx<sum;

}

void dfs(int x){
    if(x>n){
        if(check(x)){
            ans++;ans%=MOD;
        }
        return ;
    }
    book[x]=1;
    dfs(x+1);
    book[x]=0;
    dfs(x+1);

}



int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);

    cout<<ans;

    return 0;
}
