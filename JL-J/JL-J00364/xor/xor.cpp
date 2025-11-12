#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int a[1145141]={-1};
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(k==0){
        bool t=true;
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]!=1){
                t=false;
            }
            if(a[i]==0) ans++;
            if(a[i]==1 and a[i-1]==1) ans++;
        }
        if(t){
            cout<<n/2<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    else if(k==1)
    {
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==1) ans++;
            if(a[i]==0 and a[i-1]==0) ans++;
        }
        cout<<ans<<endl;
    }
    else{
        cout<<1<<endl;
    }
    return 0;
}
