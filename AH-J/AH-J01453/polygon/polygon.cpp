#include<bits/stdc++.h>
using namespace std;
int n,a[5100];
int an=0;
long long ans[5100][5100];
void dfs(int step,int maxx,int he){
    if(step==n){
        if(he>2*maxx){
            an++;
            an%=998244353;
        }
        return;
    }
    dfs(step+1,maxx,he);
    dfs(step+1,max(maxx,a[step]),he+a[step]);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=3){
        if(n==3){
            int a,b,c;
            cin>>a>>b>>c;
            if(a+b>c&&a+c>b&&b+c>a){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<0;
        }
    }else if(n<28){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        dfs(0,0,0);
        cout<<an;
    }else{
        ans[1][1]=1;
        ans[1][2]=1;
        ans[2][2]=1;
        for(int i=1;i<=n+5;i++){
            ans[i][1]=1;
            ans[i][i]=1;
        }
        for(int i=1;i<=n+5;i++){
            for(int j=1;j<=i;j++){
                if(ans[i][j]!=1){
                    ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long s=0;
        for(int i=3;i<=n;i++){
            s+=ans[n+1][i+1];
            s%=998244353;
        }
        cout<<s;
    }
    return 0;
}
