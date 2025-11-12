#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long people,ans=0,i,j;
    int a[10005][10005];
    cin>>people;
    for(int i=1;i<=people;i++)
    {
        for(int j=1;j<=3;i++)
        {
                cin>>a[i][j];
                ans+=max(a[i][j],a[i+1][j]);
                ans+=max(a[i][j],a[i][j+1]);

        }
    }
    cout<<ans;
 return 0;
}