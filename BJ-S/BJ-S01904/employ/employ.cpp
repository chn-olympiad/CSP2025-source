#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[505],k,num,cnt,ans,h[505];
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    k=s.length();
    for(int i=1;i<=n;i++){
        cin>>c[i];
        h[i]=i;
        if(c[i]==0){
            cnt++;
        }
    }
    s=" "+s;
    for(int i=1;i<=k;i++){
        if(s[i]=='1')num++;
    }
    if(num<m||n-cnt<m){
        cout<<0;
        return 0;
    }
    if(num==n){
        int res=1;
        for(int i=1;i<=n;i++){
            res=res*i%mod;
        }
        cout<<res;
        return 0;
    }
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||cnt>=c[h[i]]){
                cnt++;
                if(i-cnt>=m)break;
                if(n-cnt<m)break;
            }
            //cout<<h[i]<<" ";
        }
        //cout<<endl;
        if(n-cnt>=m)ans++;
    }while(next_permutation(h+1,h+n+1));
    cout<<ans;
    return 0;
}//g++ -Wall -std=c++14 -fsanitize=address,undefined,leak -O2 4.cpp -o 4
//time ./4