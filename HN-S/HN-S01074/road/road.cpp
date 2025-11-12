#include<bits/stdc++.h>
using namespace std;
struct uu{
    int u1,u2,u3;
}u[10010];
struct aa{
    int a1[1010];
}a[101000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,c[10010];
    int ans=0;
    char s1[550];
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u[i].u1>>u[i].u2>>u[i].u3;
        ans=u[i].u1;
        ans=min(ans,u[i].u2);
        ans=min(ans,u[i].u3);
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=0;j<n;j++){
            cin>>a[i].a1[j];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
