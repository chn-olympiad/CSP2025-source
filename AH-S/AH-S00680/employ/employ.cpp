#include<bits/stdc++.h>
using namespace std;
string s;
const int mod=998242353;
int n,m,a[505],b[505],sum,ans,f;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(s[i-1]=='1'){
            sum++;
        }
        if(!a[i]){
            f=1;
        }
    }
    if(sum<m){
        cout<<"0";
        return 0;
    }
    if(n<=11){
        for(int i=1;i<=n;i++){
            b[i]=i;
        }
        do{
            sum=0;
            for(int i=1;i<=n;i++){
                if(s[i-1]=='1'&&sum<a[b[i]]){

                }else{
                    sum++;
                }
            }
            if(n-sum>=m){
                ans=(ans+1)%mod;
            }
        }while(next_permutation(b+1,b+1+n));
        cout<<ans<<"\n";
    }else{
        ans=1;
        for(int i=2;i<=n;i++){
            ans=(ans*i)%mod;
        }
        cout<<ans;
    }
    return 0;
}
