#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,i;
    cin>>n;
    for(int l=0;l<n;i++){
        cin>>i;
        int ans=0,a[i+3][4];
        for(int j=0;j<i;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        if(a[j][1]>=a[j][2] && a[j][1]>=a[j][3])ans+=a[j][1];
        else if(a[j][2]>=a[j][1] && a[j][2]>=a[j][3])ans+=a[j][2];
        else ans+=a[j][3];
        cout<<ans<<endl;
        }

    }return 0;}
