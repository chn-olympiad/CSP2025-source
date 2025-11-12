#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(k==0){
            if(a[i]==0) ans++;
            if(i!=1 && a[i]==a[i-1]){
                a[i]=0;
                ans++;
            }
        }
        if(k==1){
            if(a[i]==1){
                a[i]=0;
                ans++;
            }
            if(i!=1 && a[i]==0 && a[i-1]==1) ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
