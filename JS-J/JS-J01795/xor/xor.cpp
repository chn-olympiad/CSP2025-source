#include<bits/stdc++.h>
using namespace std;
//look out freopen!
int n,k,ma,x,l,a[500010];
int fun(int a,int b){
    if(a!=b){
        return 1;
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(a[i],ma);
        if(a[i]==1){
            x++;
        }
    }
    if(n==2){
        if(fun(a[1],a[2])==k){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else if(k==1&&ma<=1){
        cout<<x;
    }
    else if(k==0&&ma<=1){
        x=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
               l=0;
               x++;
            }
            else{
                l++;
                if(l==3){
                    x++;
                    l=0;
                }
            }
        }cout<<x;
    }

    return 0;
}
