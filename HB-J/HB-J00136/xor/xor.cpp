#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor,out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,s=-1,r=0;
    cin>>n>>k;
    if(n<=2){
        int k,a1,a2;
        cin>>a1>>a2;
        if(a1==a2){
            cout<<1;
        }else{
        cout<<0;
        }
        return 0;
    }
    int a[n+10]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int u=a[i];
            for(int k=i+1;k<=j;k++){
                int o=a[k],uu=u,oo=o;
                while(o>0&&u>0){
                    s++;
                    o>>1<<1;
                    u>>1<<1;
                    if((o==oo&&u==uu)||(o!=oo&&u!=uu)){
                        r+=pow(2,s);
                    }
                    o>>1;
                    u>>1;
                    oo=o;
                    uu=u;
                }
            }
        }
    }
    cout<<r;
    return 0;
}
