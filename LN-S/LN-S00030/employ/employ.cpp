#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500;
int n,m;
string s;
int a[N];
const int mod=998244353;
signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool f=false;
    for(char x:s){
        if(x!='1'){ f=true;break; }
    }
    sort(a,a+n);
    int sum=1,su=1,ss=1;
    for(int i=1;i<=n;i++){// n,m
        sum*=i;
        sum%=mod;
    }
    if(n==m){ cout<<sum<<endl;return 0; }
    for(int i=1;i<=m;i++){// n,m
        su*=i;
        su%=mod;
    }
    sum/=su;
    for(int i=1;i<=(n-m);i++){// n,m
        ss*=i;
        ss%=mod;
    }
    sum/=ss;
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ren5Jie4Di4Ling5%

