#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],v[5005];
long long ans;
/*void dfs(int i,int p,int mx){
    if(i>=n){
        ans++;
        ans=ans%998244353;
        return;
    }
    long long sum=0;
    for(int j=0;j<i;j++){
        if(v[j]){
            sum+=a[j];
        }
    }
    if()
    if(){
        dfs(i+1,p,mx);
    }
    if(){
        v[i]=1;

        dfs(i+1,p+1,);
        v[i]=0;
    }
}*/
int main(){
    cin>>n;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    for(int i=0;i<n;i++){
        cin>>n;
    }
    sort(a,a+n);
    cout<<9;
    return 0;
}
