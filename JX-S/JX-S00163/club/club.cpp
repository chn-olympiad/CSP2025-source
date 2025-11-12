#include <bits/stdc++.h>
using namespace std;
int a[3];
int t,ans,flag;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int i=1;i<=3;i++)
            {
                cin>>a[i];
                sort(a+1,a+4);
            }

            if(flag<=n/2)
            {
                ans+=a[3];
                flag++;
            }
            else
            {
                ans+=a[2];
            }

        }
        cout<<ans;
    }
     return 0;
}
