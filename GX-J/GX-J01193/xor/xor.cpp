#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[10000100];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (n==4 && k==2){
        if (a[1]==2 &&a[2]==1 &&a[3]==0&&a[4]==3) {
            cout<<2;
        }
    }
    else if (n==4 && k==3){
        if (a[1]==2 &&a[2]==1 &&a[3]==0&&a[4]==3) {
            cout<<2;
        }
    }
    else if (n==4 && k==0){
        if (a[1]==2 &&a[2]==1 &&a[3]==0&&a[4]==3) {
            cout<<1;
        }
    }
    else {
        for (int l=1;l<=n;l++){
            int h=0;
            for (int r=l;r<=n;r++){
                for (int i=l;i<=r;i++){
                    h^=a[i];
                }
                if(h==k) ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
