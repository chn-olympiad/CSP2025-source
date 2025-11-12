#include<bits/stdc++.h>
using namespace std;
int n;
int m;
string s;
int c[502];
int a[502];
int mod=998244353;
int ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            flag=1;
            break;
        }
    }
    if(flag==0){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    do{
        int cnt=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0' || c[a[i]]<=cnt){
                cnt++;
            }else{
                sum++;
            }
        }
        if(sum>=m){
            //for(int i=1;i<=n;i++){
                //cout<<a[i]<<" ";
            //}
            //cout<<"\n";
            //cout<<m<<"\n";
            ans++;
            ans%=mod;
        }
    }while(next_permutation(a+1,a+1+n));
    cout<<ans;
    return 0;
}
