#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[1001],mmax=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    if(n<3) cout<<"0";
    if(n==3){
        for(int i=0;i<n;i++){
            if(mmax<a[i]) mmax=a[i];
        }
        if(2*mmax<ans) cout<<"1";
        else cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
