#include<bits/stdc++.h>

using namespace std;
const int N=5e5+5;
int n,k;
long long num[N];
long long dp[N];
vector<int> e[N];
void cl(){
    for(int le=1;le<=n;le++){
        for(int ri=le;ri<=n;ri++){
            long long m=num[le];
            for(int i=le+1;i<=ri;i++){
                m^=num[i];
            }
            if(m==k)e[ri].push_back(le);
        }
    }
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdin);
    cin>>n>>k;
    bool f_one=true;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]!=1)f_one=false;
    }
    if(f_one&&k==0){
        cout<<n/2;
        return 0;
    }
    cl();
    if(e[1].size()!=0)dp[1]=1;
    else dp[1]=0;
    for(int R=2;R<=n;R++){
        for(int x :e[R]){
            dp[R]=max(dp[x-1]+1,dp[R]);
        }
    }
    cout<<dp[n];
    return 0;
}
