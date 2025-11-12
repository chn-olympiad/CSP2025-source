#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int a[500100];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int flag=1;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]==0)
        {
            flag=0;
        }
    }
    if (flag && k==0)
    {
        cout << 0 <<endl;
        return 0;
    }
    int minn=n;
    for (int l1=1;l1<=n;l1++)
    {
        for (int r1=1;l1+r1-1<=n;r1++)
        {
            for (int l2=l1+1;l2<=n;l2++)
            {
                for (int r2=1;l2+r2-1<=n;l2++)
                {
                    if (l1!=l2 && r1!=r2)
                    {
                        int h1=a[l1];
                        for (int i=l1+1;i<=l1+r1-1;i++)
                        {
                            h1^=a[i];
                        }
                        int h2=a[l2];
                        for (int i=l2+1;i<=l2+r2-1;i++)
                        {
                            h2^=a[i];
                        }
                        if (h1==k && h2==k)
                        {
                            if ((l1<l2 && l1+r1-1<l2) || (l2<l1 && l2+r2-1<l1))
                            {
                                minn=0;
                                break;
                            }
                            else
                            {
                               int hh=max(l1+r1-1,l2+r2-1);
                               int b=r1+r2-(hh-l1+1);
                               minn=min(minn,b);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << minn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
