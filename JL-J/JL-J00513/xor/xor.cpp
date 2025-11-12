#include <bits/stdc++.h>
using namespace std;
int n,k,i,j,a[500005],x,dp;
bool c[500005]={true};
int main()
//^shi yi huo^=shi yu huo he
{
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            for(int q=j;q<=i;q++){
                if(!c[q]){
                    continue;
                }
                if(!c[q-1]){
                    x=a[q];
                    if(x==k){
                        dp++;
                        continue;
                    }
                    continue;
                }
                if(q==1){
                    x=a[q];
                    continue;
                }
                if(a[q]==k){
                    dp++;
                    c[q]=false;
                    continue;
                }
                x^=a[q];
                if(x==k){
                    dp++;
                    for(int aa=j;aa<=q;aa++){
                        c[aa]=false;
                    }
                }
            }
        }
    }
    cout<<dp;
    return 0;
}

