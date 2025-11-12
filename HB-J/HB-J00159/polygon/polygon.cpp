#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[5200],n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        for(int j=i-1;j>=0;j--){
            int sum=a[j];
            for(int x=j-1;x>=0;x--){
                if(a[x]+sum>a[i]){
                    ans+=x;
                    break;
                }else{
                    sum+=a[x];
                    continue;
                }
            }
        }
    }
    cout<<ans;
}



