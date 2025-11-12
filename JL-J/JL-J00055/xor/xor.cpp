#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],ans,cmp,cmp1;
bool flag=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=1;
    }
    if(n<=2){
        if(n==1)cout<<0;
        else if(a[2]==1)cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        while(flag==0&&cmp<=n){
             cmp=1;
             cmp1=0;
            for(int j=i;j<=cmp;j++){
                if(b[j]==1){
                    cmp1=cmp1^a[j];
                    if(cmp1==k){
                        ans++;
                        for(int k=i;k<=j;k++){
                            b[k]==0;
                            flag=1;
                            break;
                        }
                    }
                }
                else break;
            }
        }
    }
    cout<<ans;
    return 0;
}
