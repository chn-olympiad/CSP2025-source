#include<bits/stdc++.h>
using namespace std;
int h[1742999],a[555555];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int last=0,cnt=0,cur=0;
    for(int i=1;i<=n;i++)
    {
        cur^=a[i];
        last^=a[i];
        if((cur^k)==0||h[(cur^k)]==cnt+1)
        {
            cnt++;
            cur=0;
            last=0;
        }
        else h[last]=cnt+1;
    }
    cout<<cnt<<endl;
    return 0;
}
