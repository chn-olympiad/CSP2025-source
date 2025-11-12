#include<bits/stdc++.h>
using namespace std;
int n,k,num[500005],ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=i;j<=n;j++){
            x^=num[j];
            if(x==k){
                ans++;
                i=j;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n,k,num[500005],dp[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            x^=num[j];
            if(x==k){
                for(int i=1;i<=)
            }
        }
    }
    return 0;
}
*/
