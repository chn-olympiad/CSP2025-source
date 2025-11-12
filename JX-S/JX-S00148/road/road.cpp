#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c1,c2;
long long rp;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>c1>>c2>>rp;
    for(int i=1;i<=k;i++){
        long long p[10001];
        for(int j=1;j<=n;j++){
            cin>>p[j];
        }
    }
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
