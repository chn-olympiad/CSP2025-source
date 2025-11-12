#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n1=0,n0=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]==1)
            n1++;
        else if(a[i]==0)
            n0++;
    }
    if(k==1)
        cout << n1;
    else if(k==0)
        cout << n0;
    return 0;
}
