#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans=n*m;
    int s[ans],x=0;
    for(int i=1;i<ans;i++){
        cin>>s[i];
    }
    for(int i=0;i<ans;i++)
    {
        cout<<ans;
    }
    return 0;
}
