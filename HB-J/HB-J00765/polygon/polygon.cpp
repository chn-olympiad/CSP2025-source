#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],sum,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j){
                continue;
            }else{
                if(sum+a[j]>a[i]){
                    sum+=a[j];
                    ans++;
                    i=j;
                }
            }
        }
    }
    if(ans%2==0){
        cout<<ans*2+1;
    }else{
        cout<<ans*2;
    }



    return 0;
}
