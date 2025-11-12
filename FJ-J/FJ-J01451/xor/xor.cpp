#include<bits/stdc++.h>
using namespace std;
int num[500001],n,k,ans=0; // n numbers k value
void dfs(int where,int now)
{
    if(now==k)
    {
        if(where<n) dfs(where+2,num[where+1]);
        ans++;
        return;
    }
    if(where==n-1) return;
    dfs(where+1,now|num[where]);
    dfs(where+1,num[where]);
    return;
}
int main()
{
    // Fuck this CODE
    // Fuck SB Freopen
    // Fuck Tester
    // Don't FOR DAMN REMOVE THIS
    // Fuck BICH mOther SHiT FDGFDGfdGDFsaGSEgsaeGSRE43reY5$EIk56LKgW#r@15T43UHYrdgh54eYHRT CnM CodE
    freopen("xor3.in","r",stdin);
    freopen("xor.out","w",stdout);
    freopen("WARN.ERR","w",stderr);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    dfs(0,num[0]);
    cout<<ans;
    return 0;
}
