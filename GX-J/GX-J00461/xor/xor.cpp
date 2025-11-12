#include <bits/stdc++.h>
using namespace std;
long long a,b,c[1000000],d=0,e,o[1000000],p[1000000],t=0,g=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
    }
    for(int i=a;i>=1;i--){
        for(int j=i;j>=1;j--){
            for(int k=j;k<=i;k++){
                if(k==j){
                    e=c[k];
                }else{
                    e=(e^c[k]);
                }
            }
            if(e==b){
                for(int l=1;l<=t;l++){
                    if((j>=o[l]&&i<=p[l])||(j<=o[l]&&i>=p[l])){
                        g=1;
                    }
                }
                if(g!=1){
                    d++;
                    t++;
                    o[t]=j;
                    p[t]=i;
                    break;
                }
                g=0;
            }
        }
    }
    cout<<d;
    return 0;
}
