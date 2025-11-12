#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,f,f2,a[1005],x;
char c;
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> c;
        if(c=='0')f=1;
        else cnt++;
        if(f==1)x=i;
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>x)f2=1;
    }
    if(m>cnt){
        cout << 0;
        return 0;
    }
    if(m==1&&f2==0){
        cout << 0;
        return 0;
    }
    if(f){
        cout << 0;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        ans=(ans*i)%998244353;
    }
    cout << ans;
    return 0;
}