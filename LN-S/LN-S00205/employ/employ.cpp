#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    long long zongshu=1;
    long long chushu=1;
    int naixin[n];
    for(int q=0;q<n;q++)
    {
        cin>>naixin[q];
    }
    for(int q=n;q>=1;q--)
    {
        zongshu=zongshu%998244353*q%998244353;
    }
    for(int q=n-m;q>=1;q--)
    {
        chushu=q*chushu%998244353;
    }
    cout<<zongshu/chushu%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
