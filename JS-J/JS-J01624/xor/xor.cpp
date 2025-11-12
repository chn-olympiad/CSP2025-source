#include<bits/stdc++.h>
using namespace std;
long long a[511111];
vector<pair<int,int> > v;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    long long k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    long long t=0;
    int i=0,o=0;
    for(;i<n;i++)
    {
        t=0;
        for(int j=i;j>=o;j--)
        {
            t^=a[j];
            cout<<t<<" ";
            if(t==k)
            {
                ans++;
                o=i+1;
                i=o;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}