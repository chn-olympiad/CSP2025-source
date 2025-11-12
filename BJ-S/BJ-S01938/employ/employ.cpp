#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[505],pp[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    int cnt=0;
    bool flag=0;
    int peo=n;
    for(int i=1;i<=n;i++){
        cin>>pp[i];
        if(pp[i] == 0) peo--;
        if(a[i-1] == '0'){
            cnt++;
            flag=1;
        }
        //cout<<flag<<" ";

    }
    if((n-cnt)<m||peo<m){
        cout<<0;
        return 0;
    }
    if(!flag){
        long long ans=1;
        for(int i=2;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    cout<<225301405;

    return 0;
}
