#include <bits/stdc++.h>
using namespace std;
int n,m,s[1005];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    cin >> n >> m;
    for (int i=1;i<=n*m;i++)
    {
        cin >> s[i];
    }
    int x = s[1];
    sort (s+1,s+n*m+1,cmp);
    int num=1;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (s[num]==x)
            {
                if (i%2==0)
                {
                    cout << i << " " << n-j+1;
                    return 0;
                }
                else{
                    cout << i << " " << j;
                }
            }
            num++;
        }
    }
}
