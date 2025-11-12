#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500100];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    LL n,k;
    bool f=0;
    cin>>n>>k;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) f=1;
    }
    if(k==0&&f==0){
        cout<<n/2;
        return 0;
    }else if(k==0){
        bool s[500100];
        memset(s,0,sizeof 0);
        LL sum=0;
        for(LL i=1;i<=n;i++){
            if(a[i]==0){
                sum++;
            }else{
                if(s[i]==0&&s[i+1]==0&&a[i]==1&&a[i+1]==1){
                    sum++;
                    s[i]=1;
                    s[i+1]=1;
                }
            }
        }
        cout<<sum;
        return 0;
    }else if(k==1){
        LL sum=0;
        for(LL i=1;i<=n;i++){
            if(a[i]==1){
                sum++;
            }
        }
        cout<<sum;
    }
    return 0;
}
