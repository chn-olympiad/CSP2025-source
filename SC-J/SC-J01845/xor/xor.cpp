#include<bits/stdc++.h>
using namespace std;

ifstream fin("xor.in");
ofstream fout("xor.out");
int n,k,a[500001],ans,la,las[1048577];

int main()
{
    // freopen("xor.in","r",stdin);
    // freopen("xor.out","w",stdout);
    fin>>n>>k;
    for(int i=1;i<=n;i++)
        fin>>a[i],
        a[i]^=a[i-1];
    for(int i=1;i<1048576;i++)
        las[i]=-1;
    for(int i=1;i<=n;i++)
    {
        if(las[a[i]^k]>=la)
            la=i,
            ++ans;
        las[a[i]]=i;
    }
    fout<<ans<<"\n";
}