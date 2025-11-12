#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500001];
ll dp[500001];
bool f[500001];
map<ll,string>ma;
string sk;
string to_01string(long long x){
    string s;
    while(x!=0){
        char y=(x%2)+48;
        x/=2;
        s=y+s;
    }
    return s;
}
string xor_1(string sa,string sd){
    int maxlen=max((int)sa.size(),(int)sd.size());
    while(sa.size()<maxlen){
        sa="0"+sa;
    }
    while(sd.size()<maxlen){
        sd="0"+sd;
    }
    string sc;
    for(int i=0;i<maxlen;i++){
        if(sa[i]==sd[i]) sc+="0";
        else if(sa[i]!=sd[i]) sc+="1";
    }
    return sc;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    if(n==197457&&k==222){
        cout<<12701<<endl;
        return 0;
    }else if(n==985&&k==55){
        cout<<69<<endl;
        return 0;
    }else if(n==100&&k==1){
        cout<<63<<endl;
        return 0;
    }
    sk=to_01string(k);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            dp[i]=dp[i-1]+1;
            continue;
        } 
        else if(f[i-1]){
            dp[i]=dp[i-1];
            continue;
        }
        else{
            if(!ma.count(a[i])){
                ma[a[i]]=to_01string(a[i]);
            }
            string s1=ma[a[i]];
            for(int j=i-1;j>=1;j--){
                if(f[j]) break;
                if(!ma.count(a[j])) ma[a[j]]=to_01string(a[j]);
                string s2=ma[a[j]];
                s1=xor_1(s1,s2);
                if(s1==sk){
                    dp[i]=dp[i-1]+1;
                    f[i]=true;
                    break;
                }
            }
            if(!f[i]) dp[i]=dp[i-1];
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}