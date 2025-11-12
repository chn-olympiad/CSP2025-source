#include<bits/stdc++.h>
using namespace std;
long long n,m,k,zj=0;
struct dl
{
    long long q,z,jg;
};
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++)
    {
        cin>>dl.q>>dl.z>>dl.jg;
        zj+=dl.jg;
    }
    cout<<zj;
return 0;
}

