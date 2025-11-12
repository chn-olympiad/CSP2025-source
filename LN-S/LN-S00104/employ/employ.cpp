#include<bits/stdc++.h>
const int maxn=99824453;
using namespace std;
int n,m;
char a;
int v[1005];
int pe[1005];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        v[i]=a-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>pe[i];
    }
    if(m==n){
        bool f=true;
        for(int i=1;i<=n;i++){
            if(v[i]==0){
                f=false;
            }
        }
        if(f==false){
            cout<<0;
        }else{
            int ans=1;
            for(int i=1;i<=n;i++){
                ans*=i;
                ans%=maxn;
            }
            cout<<ans;
            return 0;
        }
    }else if(m==1){
        bool f=false;
        for(int i=1;i<=n;i++){
            if(v[i]==1){
                f=true;
            }
        }
        if(f==false){
            cout<<0;
        }else{
            int ans=1;
            for(int i=1;i<=n;i++){
                ans*=i;
                ans%=maxn;
            }
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
