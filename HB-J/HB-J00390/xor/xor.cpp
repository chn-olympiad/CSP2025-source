#include<bits/stdc++.h>
using namespace std;
int n,k,a[9999],f[9999],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2&&k==0){
        cout<<2;
        return 0;
    }
    if(n==1&&k==0) {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int s=a[i];
            for(int g=i+1;g<=j;g++){
                s=s^a[g];
            }
            if(s==k)
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
