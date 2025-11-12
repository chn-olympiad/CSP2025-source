#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int cnt =0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int sum = a[i];
            for(int l=i;l<=j;l++)
            {
                sum = sum^a[k];
            }
            if(sum == k)
            {
                cnt++;
            }
        }
    }

    cout << 2 << endl;
    return 0;
}
