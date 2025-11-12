#include<bits/stdc++.h>
using namespace std;
long long n,k,x[500010],f[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(k==0){
        long long cnt=0;
        for(int i=1;i<=n;i++){
            if((x[i]==x[i+1]&&x[i]!=x[i-1])||x[i]==0){
                cnt++;
            }
        }
        cout<<cnt;
    }
    else{
        long long X=0,cnt=0;
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                for(int i=l;i<=r;i++){
                    if(f[i]==1){
                        break;
                    }
                    X^=x[i];
                    f[i]=1;
                }
                if(X==k){
                    cnt++;
                }
                else{
                    for(int i=l;i<=r;i++){
                        f[i]=0;
                    }
                }
                X=0;
            }
        }
        cout<<cnt;
    }

    return 0;
}
