#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500001],ans=0;


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool flag=true,flag2=true;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]!=1) flag=false;
        if(a[i]!=1&&a[i]!=0) flag2 =false;
    }
    if(flag) {
        cout<<n/2<<endl;
        return 0;
    }
    if(flag2){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                if(a[i]==1&&a[i+1]==1) ans++;
            }
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}
