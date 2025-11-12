#include<bits/stdc++.h>
using namespace std;
int a[500025],b[500025];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n = 0,k = 0,l = 0;
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        int sum = 0;
        for(int j = i;j<=n;j++)
        {
            sum = a[i];
            if(j == i&&a[j] == k&&b[j] == 0)
            {
                l++;
                b[i] = 1;
                break;
            }
            else if(j > i)
            {
                sum = (sum ^ a[j]);
                if(sum == k)
                {
                    int k = 0;
                    for(int q = i;q <= j;q++)
                    {
                        if(b[q] == 1)
                        {
                            k++;
                        }
                        else
                        {
                            b[q] = 1;
                        }
                    }
                    if(k == 0)
                    {
                        l++;
                    }
                }
            }
        }
    }
    cout<<l;
    return 0;
}

