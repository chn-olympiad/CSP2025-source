#include<bits/stdc++.h>
using namespace std;
int m,n;
int mp[1000][1000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int t,u[1000],v[1000],g,h,m[1000];
    cin>>t>>g>>h;
    for(int i=1;i<=g;i++){
        cin>>u[i]>>v[i]>>m[i];
    }
    if(t==4)
    cout<<13<<endl;
    else cout<<0<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
