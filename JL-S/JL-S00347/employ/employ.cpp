#include<bits/stdc++.h>
using namespace std;
string s;
int c[505];
int n,m,ans=1,mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    //shenjibaowoguojigeba
    //My deal computer.Could you please pass a couple of testing points for me?
    cin>>n>>m;
    bool flag=true,flag1=true,flag2=true;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]!=0){
            flag=false;
        }
        if(s[i]!=1){
            flag=false;
        }
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(c[i]!=0){
            flag1=false;
        }
    }
    if(flag2&&flag1&&m==1){
        for(int i=1;i<=n;i++){
            ans=(ans*i)%mod;
        }
        cout<<ans;
        return 0;
    }
    if(flag&&flag1&&m==n){
        for(int i=1;i<=n;i++){
            ans=(ans*i)%mod;
        }
        cout<<ans/(ans/n)%mod;
        return 0;
    }
    int num=n;
    sort(c+1,c+n+1);
    for(int i=0;i<num;i++){
        if(c[i]<i){
            num--;
            for(int j=i;j<num;j++){
                c[i]=c[i+1];
            }
        }
    }
    for(int i=0;i<num;i++){
        ans=ans*(c[i]-i+1)%mod;
    }
    cout<<ans%mod;
    return 0;
}
