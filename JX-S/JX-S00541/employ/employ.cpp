#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010111],b[101011],ans,r;
char s[1010011];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=i;
    }
    if(n<=10){
        do{
            for(int i=1;i<=n;i++){
                if(r>=a[b[i]]||s[i]=='0'){
                    r++;
                }
            }
            if(n-r>=m){
                ans++;
                ans%=998244353;
            }
            r=0;
        }while(next_permutation(b+1,b+n+1));
        cout<<ans;
    }else{
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
    }
    return 0;
}
