#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005];
int t[1100000];
int timec[1100000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    int ans=0;
    int las=0;
    for(int i=1;i<=n;i++)
    {
        t[s[i-1]^k]++;
        timec[s[i-1]^k]=i;
        if(t[s[i]]>0 and timec[s[i]]>las)
        {
            ans++;
            t[s[i]]=0;
            las=i;
        }
    }
    cout<<ans;
}//10:00
