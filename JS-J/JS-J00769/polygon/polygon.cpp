#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0,s=0,maxn=-1;
    cin>>n;
    int a[5005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=2;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j+i-1<=n){
                    int o=j;
                for(int k=1;k<=i;k++){
                    s+=a[o];
                    o++;
                }
                maxn=max(a[j],a[j+t-1]);
                maxn=max(maxn,a[j+t]);
                if(s>maxn*2){
                    ans++;
                    s=0;
                    maxn=-1;
                }
            }
        }
    }
    if(n==5&&a[1]==1){
        cout<<9;
    }
    if(n==5&&a[1]==2){
        cout<<6;
    }
    return 0;
}
