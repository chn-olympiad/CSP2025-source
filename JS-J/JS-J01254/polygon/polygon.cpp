#include<bits/stdc++.h>
using namespace std;
int n;
int i;
int p(int m,int h,vector<int> a,vector<int> b,vector<vector<int>> dp){
    int temp;
    for(int k2=0;k2<n;k2++){
        for(int k3=0;k3<n-1;k3++){
            if(b[k3+1]>b[k3]){
                temp=b[k3+1];
                b[k3+1]=b[k3];
                b[k3]=b[k3+1];
            }
        }
    }
    for(int k=0;k<n;k++)dp[k][i]=b[k];
    i++;
    for(int k6=0;k6<1000;k6++){
        for(int k2=0;k2<n;k2++){
            for(int k3=0;k3<n-1;k3++){
                if(dp[k3+1][k6]<dp[k3][k6]){
                    temp=dp[k3+1][k6];
                    dp[k3+1][k6]=dp[k3][k6];
                    dp[k3][k6]=temp;
                }
            }
        }
    }
    int i=0;
    for(int k4=0;k4<1000;k4++){
        for(int k5=0;k5<n;k5++){
            if(dp[k5][k4]!=b[k5]){
                break;
            }
            if(k5==n-1)i=1;
        }
        if(i==1)return 0;
    }
    int count=0;
    for(int k1=0;k1<n;k1++){
        if(a[k1]==-10000)continue;
        temp=a[k1];
        a[k1]=-10000;
        m=max(m,k1);
        count+=p(m,h+k1,a,b,dp);
        a[k1]=temp;
    }
    if(h>2*m){
        count++;
    }
    return count;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int count=0;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    vector<vector<int>> dp(n,vector<int>(1000,0));
    int temp;
    for(int k=0;k<n;k++){
            cin>>a[k];
    }
    for(int k1=0;k1<n;k1++){
        temp=a[k1];
        a[k1]=-10000;
        b[0]==k1+1;
        count+=p(k1,k1,a,b,dp);
        a[k1]=temp;
    }
    cout<<count;
    return 0;
}

