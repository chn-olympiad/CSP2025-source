#include <bits/stdc++.h>
using namespace std;
int h[1000];
int main()
{
    forepen("xor.in","r",stdin)
    forepen("xor.out","w",stdout)
    int q,a,b;
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        int minn=h[a],maxn=h[a];
        for(int i=a+1;i<=b;i++)
        {
            if(h[i]<minn)
            {
                minn=h[i];
            }
            if(h[i]>maxn)
            {
                maxn=h[i];
            }
        }
        cout<<maxn-minn;
    }
    return 0;
}
