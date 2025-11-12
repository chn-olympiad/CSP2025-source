#include <iostream>
#include <string>
using namespace std;
long long f(int n){
    long long ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5];
    string str;
    cin>>str;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(str[i]=='0'){
            flag++;
            break;
        }
    }
    if(flag&&m==n)cout<<0;
    if(flag==0)cout<<f(n);
    return 0;
}