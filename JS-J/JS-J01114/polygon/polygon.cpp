#include<bits/stdc++.h>
using namespace std;
int m[5001][5001],n;
int ans=0;
int find(int num,int i){
    int ans=0;
    while(m[i][ans]<n)
        ans++;

    return ans;
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[0][i];
    }
    sort(m[0],m[0]+n);
    //cout<<find(3,0);
    for(int i=1;i<n;i++){
    for(int j=0;j<n-i;j++)
        m[i][j]=m[0][j]+m[i-1][j+1];
        }
    for(int i=3;i<n;i++){
        for(int j=i-1;j<n;j++)
        for(int k=j-1;k>i-3;k--){
            int sss=find(m[0][k],i-3);
            ans=ans+sss-k;
            ans%=998244353;
        }
    }
    cout<<ans-1;
    return 0;
}
