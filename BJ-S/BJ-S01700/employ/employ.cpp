#include<bits/stdc++.h>
using namespace std;
struct ax{
    string a,b;
};
long long n,m,k,q,ans=1;
const long long lk=998244353;
int na[100005],ka[100005];
bool you=1,me=1;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>na[i];
        if(na[i]!=1){
            you=0;
        }
        if(na[i]!=0){
            me=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>ka[i];
    }
    if(you==1){
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=lk;
        }
    }else if(m==n){
        ans=0;
    }else if(m==1 && !(me==1)){
         for(int i=1;i<=n;i++){
            ans*=i;
            ans%=lk;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
