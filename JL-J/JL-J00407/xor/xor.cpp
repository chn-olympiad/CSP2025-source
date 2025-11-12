#include<bits/stdc++.h>
using namespace std;
int a[500010],k;
int main(){

    int n,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) sum++;
    }
    if(k==1) cout<<sum;
    else{
        int ans=0;
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                flag=false;
                ans++;
            }
            if(a[i]==1){
                if(flag==true) ans++;
                flag=~flag;
            }
        }
        cout<<ans;
    }
    return 0;
}
