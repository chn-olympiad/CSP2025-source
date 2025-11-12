#include<bits/stdc++.h>
using namespace std;
int num[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    int k;
    cin>>n>>k
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        num[i]+=num[i-1];
    }
    int a=0;
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            if(num[r]-num[l-1]==0)
            {
                a++;
            }
        }
    }
    cout<<a;
    return 0;
}
