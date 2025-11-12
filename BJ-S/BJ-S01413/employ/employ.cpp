#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[505];
bool vis[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    bool solve1_flag=1;
    int hardnum=0;
    for(int i=0;i<s.size();i++){
        if (s[i]=='0'){
            solve1_flag=0;
            hardnum++;
        }
    }
    int is0=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]==0){
            is0++;
        }
    }
    if (hardnum>(n-m)){
        cout<<0;
        return 0;
    }
    if (m==n||solve1_flag){
        if (!solve1_flag||is0>(n-m)){
            cout<<0;
        }
        else{
            long long ans=1;
            long long mn=0;
            bool whflag=1;
            while(whflag){
                whflag=0;
                for(int i=1;i<=n;i++){
                    if (mn>=a[i]&&!vis[i]){
                        mn++;
                        //cout<<a[i]<<endl;
                        whflag=1;
                        vis[i]=1;
                    }
                }
            }
            //cout<<mn<<endl;
            for (int i=2;i<=n-mn;i++){
                ans*=i;
                ans%=MOD;
            }
            cout<<ans;
        }
    }
    else if (m==1){
        long long ans=1;
        for (int i=2;i<=n;i++){
            ans*=i;
            ans%=MOD;
        }
        cout<<ans;
    }
    return 0;
}