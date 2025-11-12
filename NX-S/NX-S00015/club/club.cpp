#include<bits/stdc++.h>
using namespace std;
int t,n,q[10],s=0,ans=0,sz[10];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int b=0;
    for(int a=1;a<=t;a++){
        cin>>n;
        int h=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>q[j];
                if(q[j]<s){
                    s=q[j];
                }
                else {
                    b=j;
                    s=q[j];
                }
            }
            ans=ans+q[b];
        }
        cout<<ans<<endl;
    }
    return 0;
}
