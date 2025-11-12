#include<bits/stdc++.h>
using namespace std;

int n,k,a[500010],b[500010],ans,c[500010];
void abc(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[j]|b[i]==k){
                if(c[i]!=1&&c[j]!=1){
                    ans++;
                    for(int k=i;k<=j;k++){
                      c[i]=1;
                    } 
                    if(c[i]==1||c[j]==1) ans--;
                }
                
            }
        }
    }
    cout<<ans;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
            c[i]=1;
        }
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=a[i]|b[i-1];
        if(b[i]==k){
            if(c[i]!=1&&c[i-1]!=1)
            ans++;
            c[i]=1;
            c[i-1]=1;
        }
    }

    abc();
    return 0;
}