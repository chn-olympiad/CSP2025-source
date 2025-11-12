#include <bits/stdc++.h>
using namespace std;


int seat[11][11];
int wei[105];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i<n*m+1;i++)
    {
        cin >> wei[i];
    }
    int xm = wei[1];
    sort(wei+1,wei+(n*m)+1);
    int xm_wei = 0;
    for (int i = 1;i<n*m+1;i++)
    {
        if (wei[i] == xm) xm_wei = i;
    }
    //pf1
    if (m == 1 && xm_wei <= n)
    {
        cout << m << " " << xm_wei;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
