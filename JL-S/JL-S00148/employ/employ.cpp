#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1000],ans,no,z=1;
bool o;
string s;
int main(){
    freopen("employ4.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            no++;
        }
    }
    if(m==1){
        for(int i=0;i<n-no;i++){
            if(s[i]=='1'){
                o=1;
                break;
            }
        }
        if(o){
            ans=1;
            for(int i=1;i<=n-no;i++){
                ans*=i%988244353;
                ans%=988244353;
            }
        }
    }
    else{
        ans=1;
        for(int i=1;i<=n-no;i++){
            ans*=i%988244353;
            ans%=988244353;
        }
    }
    cout<<ans*n%988244353;
    return 0;
}
