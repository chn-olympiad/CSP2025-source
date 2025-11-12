#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5],cf[N];
struct node{
    int num,id;
}f[N*2];
bool cmp(node x,node y){
    return x.num>y.num;
}int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int flag1=0,flag2=0;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            flag1 += (a[i][2]==0);
            flag2 += (a[i][3]==0);
        }
        int sum=0;
        for (i = 1; i <= n; i++)
            sum += a[i][1];
        if (flag2 == n)
        {
            for (i = 1; i <= n; i++)
                cf[i] = a[i][2]-a[i][1];
            stable_sort(cf+1,cf+1+n,greater<int>());
            for (i = 1; i <= n/2; i++)
                sum += cf[i];
            cout << sum << "\n";
            continue;
        }
        int idx=0;
        for (i = 1; i <= n; i++)
        {
            f[++idx].num = a[i][2]-a[i][1];
            f[idx].id = 1;
            f[++idx].num = a[i][3]-a[i][1];
            f[idx].id = 2;
        }
        stable_sort(f+1,f+1+idx,cmp);
        int cnt1=0,cnt2=0;
        for (i = 1; i <= n/2; i++)
        {
            sum += f[i].num;
            if (f[i].id == 1)
                cnt1++;
            else
                cnt2++;
        }
        i = n/2+1;
        while (i<=n*2 && (cnt1<n||cnt2<n) && f[i].num>0)
        {
            if (f[i].id == 1)
            {
                if (cnt1 < n)
                {
                    cnt1++;
                    sum += f[i].num;
                }
            }
            else
            {
                if (cnt2 < n)
                {
                    cnt2++;
                    sum += f[i].num;
                }
            }
            i++;
        }
        cout << sum << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}