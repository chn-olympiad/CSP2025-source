#include<bits/stdc++.h>
using namespace std;
long long n;
int t,d,mn=0;
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
    cin>>t;
    for(int b=0;b<t;b++){
            cin>>n;
            int a[n][3];
            for(int i=0;i<n;i++){
                    for(int j=0;j<3;j++){
                        cin>>a[n][1]>>a[n][2]>>a[n][3];
                        if(a[n][1]>=a[n][2]||a[n][1]>=a[n][3])
                            int mn=+a[n][1];
                        else if(a[n][2]>=a[n][1]||a[n][2]>=a[n][3])
                            int mn=+a[n][2];
                        else int mn=+a[n][3];
                        cout<<mn
            }
        }
    }
    return 0;
}
