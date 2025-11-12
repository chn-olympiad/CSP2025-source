#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=262130;
const int N=20;
const int mod=998244353;
int n,m;
string s;
int c[N];
vector<int> v[N];
int dp[N][MAXN];
int opt=1;
void work(){
    for(int i=0;i<=opt;i++){
        int ans=0,x=i;
        while(x){
            if(x%2==1) ans++;
            x/=2;
        }
        v[ans].push_back(i);
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;//,s=" "+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++) opt*=2;
    opt--;
    work();
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            int x=v[i][j],xx=x,cnt=1;
            //cout<<"i: "<<i<<" "<<x<<"\n";
            while(cnt<=n){
                //cout<<xx<<"\n";
                if(xx%2==0){
                    for(int z=0;z<=i;z++){
                        int ct=i-z;
                        if(ct<c[cnt] && s[i]=='1'){
                            //cout<<z<<" "<<x<<" "<<z+1<<" "<<x+(1<<(cnt-1))<<"\n";
                            dp[z+1][x+(1<<(cnt-1))]+=dp[z][x],dp[z+1][x+(1<<(cnt-1))]%=mod;
                        }
                        else{
                            //cout<<z<<" "<<x<<" "<<z<<" "<<x+(1<<(cnt-1))<<"\n";
                            dp[z][x+(1<<(cnt-1))]+=dp[z][x],dp[z][x+(1<<(cnt-1))]%=mod;
                        }
                    }
                }
                xx/=2;
                cnt++;
            }
        }
    }
    int tot=0;
    for(int i=m;i<=n;i++){
        tot+=dp[i][opt];
        tot%=mod;
    }
    cout<<tot;
    return 0;
}
