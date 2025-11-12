#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N],ind[N],cnt[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        int s=0;
        for(int i=0;i<n;i++)
        {
            if(b[i]==0&&c[i]==0)s+=a[i];
            if(c[i]==0)s+=max(a[i],b[i]);
            else s+=max(a[i],max(b[i],c[i]));
        }
        cout<<s;
    }
    return 0;
}
