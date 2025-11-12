#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,m=0,a[10001]={},qian[10001]={},s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=1;i<=n;i++){
        m+=a[i];
        qian[i]=m;
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[i]<qian[j]){
                s++;
            }
        }
    }
    cout<<s%998,244,353;
    return 0;
}
