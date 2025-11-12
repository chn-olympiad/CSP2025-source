#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
const long long cons=998244353;
vector<int> a(5005);
vector<int> v;
vector<int> e;
void dfs(int side,int start,long long sum){
    if(v.size()==side){
        int max_num=-1;
        for(int i=0;i<v.size();i++){
            max_num=max(max_num,v[i]);
        }
        if(sum>max_num*2){
            ans++;
            ans=ans%cons;
        }
        v.clear();
        return;
    }
    for(int i=start;i<n-1;i++){
        sum+=a[i];
        v.push_back(a[i]);
        dfs(side,i+1,sum);
        sum-=a[i];
        v.pop_back();
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f=true;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1){
            f=false;
        }
    }
    if(n==3){
        if(a[0]+a[1]+a[2]>max({a[0],a[1],a[2]})*2){
            cout<<1<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }else if(f){
        vector<vector<long long>> c(n+1,vector<long long>(n+1,1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(i==j){
                    c[i][j]=1;
                }else{
                    c[i][j]=c[i-1][j-1]+c[i-1][j];
                    c[i][j]=c[i][j]%cons;
                }
            }
        }
        for(int i=3;i<=n;i++){
            ans=ans+c[n][i];
            ans=ans%cons;
        }
        cout<<ans<<'\n';
    }else{
        for(int i=3;i<=n;i++){
            dfs(i,0,0);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
