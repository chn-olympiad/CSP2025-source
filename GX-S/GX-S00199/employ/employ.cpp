#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
ll ans=0,cnt=1,a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,num=0;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)num++;
    }
    if(n==m){
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cout<<"0";
                return 0;
            }
        }
        if(num>0){
            cout<<"0";
            return 0;
        }
        for(int i=1;i<=n;i++)cnt=cnt*i%MOD;
        cout<<cnt;
        return 0;
    }
    return 0;
}
