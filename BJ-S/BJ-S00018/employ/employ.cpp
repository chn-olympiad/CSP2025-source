#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],ans,cnt1,a[510],f=1,ss,fa,p=998244353;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    fa=1;
    for(int i=1;i<=n;i++){
        fa=fa*i;
        fa%=p;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        a[i]=i;
        if(c[i]==0){
            ss++;
        }
    }
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]!='1'){
            f=0;
        }
    }
    if(f==1){
        if(n-ss<m){
            cout<<0;
        }else{
            cout<<fa;
        }
        return 0;
    }
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cnt>=c[a[i]]){
                cnt++;
                continue;
            }
            if(s[i]=='0'){
                cnt++;
            }
        }
        if(n-cnt>=m){
            ans++;
            ans%=p;
        }
    }while(next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}
