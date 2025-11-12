#include<bits/stdc++.h>
using namespace std;
int n,k,a[550000];
pair<int,int>dp[550000];
int x[550000];
bool b;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        dp[i].first=dp[i-1].first;
        b=true;
        for(int j=1;i-j>=0;j++){
            if((dp[i-j].second^a[i])==k&&dp[i-j].first+1>dp[i].first){
                x[i]=i-j;
                dp[i].first=dp[i-j].first+1;
                dp[i].second=0;
                b=false;
                break;
            }
        }
        if(b) dp[i].second=dp[i-1].second^a[i];
    }
    printf("%d",dp[n].first);
    return 0;
}
