#include <iostream>
using namespace std;
const int A=500007;
int cnt=0,k,n,q[A],t[A];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>q[i];
    int mn=0;
    for(int i=1,j,num=q[i];i<=n;i=max(i+1,mn),num=q[i])
    {
        for(j=i;j<=n;++j,num^=q[j])
        {
            if(num==k)
            {
                mn=j+1;
                ++cnt;
                break;
            }
        }
    }
    cout<<cnt<<' ';
    return 0;
}
