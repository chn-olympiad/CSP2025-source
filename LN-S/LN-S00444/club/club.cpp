#include<bits/stdc++.h>
using namespace std;
int x[100010],y[100010],z[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x,y,z;
        int ret=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            ret+=max(x,max(y,z));
        }
    }
    cout<<ret<<endl;
    return 0;
}