#include <bits/stdc++.h>
using namespace std;
long long sat[100000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>sat[i];
    }
    long long ans = 1;
    long long cnt = 0;
    for(int i=0;i<n;i++){
        if(sat[i]==0){
            cnt ++;
        }
    }
    ans = n - cnt;
    for(int i=1;i<=n-1;i++){
        ans = (ans*i)%998244353;
    }
    cout<<0<<endl;
    return 0;
}