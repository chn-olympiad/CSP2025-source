#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t[(1<<20)+5],l,ans,sum[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],sum[i]=(sum[i-1]^a[i]);
    t[0]++;
    for(int i=1;i<=n;i++)
    {
        if(t[sum[i]^k])
        {
            ans++;
            for(int j=l;j<i;j++)t[sum[j]]--;
            l=i;
        }
        t[sum[i]]++;
    }
    cout<<ans;
    return 0;
}
/*
g++ xor.cpp -o xor
xor.exe

//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);

zmx ak ioi

luogu/atcoder/cf:zzwsj 
*/
