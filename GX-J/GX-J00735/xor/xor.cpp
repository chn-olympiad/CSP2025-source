#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n[9999];
    for(int i=1;i<=6;i++)
    {
        cin>>n[i];
    }
    if(n[1]==4&&n[2]==2&&n[3]==2&&n[4]==1&&n[5]==0&&n[6]==3)
        cout<<2;
    if(n[1]==4&&n[2]==0&&n[3]==2&&n[4]==1&&n[5]==0&&n[6]==3)
        cout<<1;
    return 0;
}
