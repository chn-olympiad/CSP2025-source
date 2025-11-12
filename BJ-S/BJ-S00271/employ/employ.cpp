#include<bits/stdc++.h>
using namespace std;
int n,m,a[600],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    do{
        int fl=0,use=0;
        for(int i=1;i<=n;i++){
            if(fl>=a[i]||s[i-1]=='0')fl++;
            else use++;
        }
        if(use>=m)ans++;
        ans%=998244353;
    }while(next_permutation(a+1,a+n+1));
    cout<<(ans)%998244353;
    return 0;
}
