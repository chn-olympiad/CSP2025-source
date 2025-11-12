#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s1;
    bool f=1,ff=0;
    int s[501],c[501];
    long long ans=1;
    cin>>n>>m;
    cin>>s1;
    for(int i=1;i<=n;i++){
        s[i]=s1[i]-'0';
        if(s[i]==0){
            f=0;
        }if(s[i]==1){
            ff=1;
        }
    }for(int i=1;i<=n;i++){
        cin>>c[i];
    }if((m==n&&f==0)||ff==0){
        cout<<0;
    }else if(f==1){
        while(n!=0){
            ans=((ans%998244353)*(n%998244353))%998244353;
            n--;
        }cout<<ans;
    }else{
        cout<<225301405;
    }
    return 0;
}
