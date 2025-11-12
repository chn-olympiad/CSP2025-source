#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
const int N=2e5+5;
string a1[N],a2[N],b1,b2;
int h1[N],h2[N];
int base=37;
int dp[N];
unordered_map<int,vector<int> > tong1;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i];
        for(int j=a1[i].size()-1;j>=0;j--)
            h1[i]=h1[i]*37+(a1[i][j]-'a');
        for(int j=a2[i].size()-1;j>=0;j--)
            h2[i]=h2[i]*37+(a2[i][j]-'a');
        tong1[h1[i]].push_back(i);
    }
    for(int i=1;i<=q;i++){
        cin>>b1>>b2;
        if(b1.size()!=b2.size()) cout<<"0\n";
        b1=" "+b1;
        b2=" "+b2;
        dp[0]=1;
        for(int j=1;j<=b1.size()-1;j++){
            if(b1[j]==b2[j]) dp[j]=dp[j-1];
            int h=0,hh=0;
            for(int k=j;k>=1;k--){
                h=h*37+(b1[k]-'a');
                hh=hh*37+(b2[k]-'a');
                int tmp=0;
                for(auto _1:tong1[h])
                    if(h2[_1]==hh) tmp++;
                dp[j]+=dp[k-1]*tmp;
            }
        }
        cout<<dp[b1.size()-1]<<'\n';
        for(int j=1;j<=b1.size()-1;j++) dp[j]=0;
    }
    return 0;
}
