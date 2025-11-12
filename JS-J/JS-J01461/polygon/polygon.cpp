#include<bits/stdc++.h>
using namespace std;
long long a[5000],n,ans=0;
long long mod=998244353;
long long max(long long a,long long b){
    if(a>b) return a;
    return b;
}
int main(){

  //  freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    long long fa=2;
    for(int i=1;i<=n;i++){
        fa*=2;
    }

    for(int i=1;i<=fa;i++){
        string s="";
        int c=fa;
        while(c){
            s+=c%2+'0';
            c/=2;
        }

        int mx=0,he=0,sum=0;
        for(int j=0;j<=n-1;j++){
            if(s[j]=='1'){
                mx=max(mx,a[j]);
                he+=a[j];
                sum++;
            }
        }
        if(he>mx*2&&sum>=3) ans++;
    }
    cout<<ans;
    return 0;
}
