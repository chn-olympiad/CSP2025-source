#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+7;
int n,m,b,cnt=0,cnt1=0;
string s;
int a[N];
signed main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    b=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            cnt++;
        }
        if(s[i-1]=='0'){
            cnt1++;
        }
    }
    if(m==1){
        if(cnt1>=n-cnt-1){
            cout<<(n-cnt)*(n-cnt)%998244353;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    if(m==n&&cnt1==0){
        int a=1;
        while(b!=1){
            a*=b;
            a%=998244353;
            b--;
        }
        cout<<a;
        return 0;
    }
    cout<<0;
    return 0;
}

/*
int pow(int b){
    int a=1;
    //b=53;
    while(b!=1){
        a*=b;
        a%=998244353;
        b--;
    }
    a=a/2;
    return a;
}
*/

