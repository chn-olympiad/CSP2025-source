#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[1000],po[1000],m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int o;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]){
            o=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        int s=0;
        for(int j=1;j<=n;j++){
            s+=a[i];
        }
        if(n>=3 && s>=o*2){
            m+=1;
        }
        else{
            continue;
        }
    }
    cout<<m;
    return 0;
}
