#include <bits/stdc++.h>
using namespace std;
int h[100];
int main()
{
    forepen("number.in","r",stdin)
    forepen("number.out","w",stdout)
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

