#include<iostream>
using namespace std;
string s;
int n,m,c[1005],num,ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            num++;
        }
        if(s[i]=='1'&&num<c[i]){
            ans++;
        }
    }
    cout<<ans%998244353;
    return 0;
}
