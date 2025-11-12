#include <bits/stdc++.h>
using namespace std;
int t,n,n2,ans[3];
int main(){
    freopen("clud.in","r",stdin);
    freopen("clud.out","w",stdout);
    cin>>t;
    for(int i=i;i<t;i++){
        cin>>n;
        n2=n/2;
        int a[3],b[n],c[3][n];
        for(int l=1;l<=n;l++){
            for(int j=1;j<=3;j++){
                cin>>a[i];
            }
            for(int f=1;f<=3;f++){
                c[f][l]=a[l];
            }
        }
        sort(b+1,b+1+n2);
        for(int k=1;k<=n2;k++){
            ans[i]+=b[k];
        }
    }
    for(int i=1;1<=t;i++){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
