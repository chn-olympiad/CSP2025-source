#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int dp[MAXN][3];
int a[MAXN][3],b[MAXN];
/*
void f(n){
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=max(dp[i-1][j]+a[i-1][j],)
        }
    }
}
*/
bool cmp(int n1,int n2){
    return n1>n2;
}
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","r",stdout);
    int t;cin>>t;
    int flag=0;
    for(int i=0;i<t;i++){
        memset(b,0,sizeof b);
        memset(a,0,sizeof a);
        int n;cin>>n;
        for(int j=0;j<n;j++){
            cin>>b[j]>>a[j][1]>>a[j][2];
            if(a[j][1]!=0||a[j][1]!=0)flag=1;
        }
        int sum=0;
        if(flag==0){
            sort(b,b+n,cmp);
            for(int s=0;s<n/2;s++){
                sum+=b[s];
            }
            cout <<sum<<"\n";
        }
    }

    return 0;
}
