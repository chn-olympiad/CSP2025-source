#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],ans=0;
char c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>c;
    for(int i=1;i<=n;i++) cin>>a[i];
    int tmp=0;
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='1') tmp++;
    }
    if(tmp==strlen(c)||m==1){
        ans=1;
        while(n>0){
            ans%=998244353;
            ans*=n;
            n--;
        }
        cout<<ans%998244353;
        return 0;
    }
    sort(a+1,a+n+1);
    int weiguo=0,sum=0;
    for(int i=1;i<=n;i++){
        if(weiguo>=a[i]||c[i-1]=='0') weiguo++;
        else sum++;
    }
    if(sum>=m) ans=1;
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            cnt++;
            ans*=cnt;
            ans%=998244353;
        }
        else cnt=1;
    }
    cout<<ans;
    return 0;
}
