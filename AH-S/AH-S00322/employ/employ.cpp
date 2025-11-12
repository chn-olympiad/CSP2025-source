#include<bits/stdc++.h>
using namespace std;

string s;
int n,m;
long long INF=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    bool c=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            c=1;
        }
    }
    int t=n;
    for(int i=1,c;i<=n;i++){
        cin>>c;
        if(c==0){
            t--;
        }
    }
    if(t<m){
        cout<<0;
        return 0;
    }
    long long ans=1;
    for(int i=t;i>=2;i--){
        ans=ans*i%INF;
    }
    long long sum=1;
    for(int i=1;i<=n-t;i++){
        sum=sum*i%INF;
    }
    cout<<(ans+sum)%INF;
    return 0;
}
