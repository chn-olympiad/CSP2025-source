#include<bits/stdc++.h>
using namespace std;
struct wo
{
    int a1,a2,a3;
}q[100010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>q[i].a1>>q[i].a2>>q[i].a3;
            cnt+=q[i].a1;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
