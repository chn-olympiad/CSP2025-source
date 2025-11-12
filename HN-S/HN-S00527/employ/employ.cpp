#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[500];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+1+n);
    int ans=1,now=1,cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            now++;
        }
        else{
            ans=(ans*(n-now+1))%mod;
            cnt++;
            for(int j=now;j<=n;j++){
                if(cnt<c[j]){
                    now=j;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
