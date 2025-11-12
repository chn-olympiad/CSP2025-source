#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ma,ans,sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        for(int p=1;p<=n;p++){
            sum=0;
            ma=0;
            for(int j=p;j<=p+i;j++){
                if(a[j]>ma){
                    ma=a[j];
                }
                sum+=a[j];
            }
            if(sum>ma*2)  ans++;
        }
    }
    cout<<ans;
    return 0;
}
