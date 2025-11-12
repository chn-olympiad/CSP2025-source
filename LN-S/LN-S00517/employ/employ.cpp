#include <bits/stdc++.h>
using namespace std;

int n,m;
bool s[101];
int c[101];
int order[101];
long long ans=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    char ci;
    for(int i=0;i<n;i++){
        cin>>ci;
        s[i]=(ci=='1');
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
        order[i]=i;    
    }
    bool flag=true;
    for(int i=0;i<n;i++) if(!s[i]) flag=false;
    if (flag) {
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans<<endl;
        return 0;
    }
    do{
        int count=0;
        int pass=0;
        for(int i=0;i<n;i++){
            if(count>=c[order[i]]) continue;
            if(!s[i]) count++;
            else pass++;
            if(pass>=m) break;
        }
        if(pass>=m) {
            ans+=1;
            ans%=998244353;
        }
    }while(next_permutation(order,order+n));
    cout<<ans<<endl;
    return 0;
}