#include<bits/stdc++.h>
using namespace std;
int t,ans1,ans2,ans3,ansz;
int a[50005][50005],n[5005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            cin>>a[j][3];
        }
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n[i];j++){
            if(a[1][3]>a[2][3]&&a[1][3]>a[3][3]){
                ans1++;
                ansz+=a[1][3];
            }
            if(a[2][3]>a[1][3]&&a[2][3]>a[3][3]){
                ans2++;
                ansz+=a[2][3];
            }
            if(a[3][3]>a[2][3]&&a[3][3]>a[1][3]){
                ans3++;
                ansz+=a[3][3];
            }
        }
    for(int i<=t;i++){
        if(ans1<n[i]/2&&ans2<n[i]/2&&ans3<n[i]/2){
            cout<<ansz;
        }
    }
}
