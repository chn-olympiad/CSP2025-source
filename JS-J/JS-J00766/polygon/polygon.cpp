#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=0;
        }
    }
    sort(a+1,a+n+1);
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*a[3]){
            cout<<1<<endl;
            return 0;
        }
        else{
            cout<<0<<endl;
            return 0;
        }
    }
    if(f){
        int ans=1;
        for(int i=n-2;i>=1;i--){
            int j=i;
            while(j>0){
                for(int k=j;k>=1;k--){
                    ans+=k;
                }
                j--;
            }
            cout<<ans<<endl;

        }
        cout<<ans<<endl;
    }
    return 0;
}
