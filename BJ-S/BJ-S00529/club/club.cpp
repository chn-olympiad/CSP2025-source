#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define fin freopen("club.in","r",stdin);
#define fout freopen("club.out","w",stdout);
using namespace std;
int tests,n,ans;
int a[100005][5],b[5];
int favor[100005],loss[100005];
int losss[100005],lossss;
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tests;
    while(tests--)
    {
        b[1]=b[2]=b[3]=lossss=ans=0;
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
            {
                favor[i]=1;
                loss[i]=a[i][1]-max(a[i][2],a[i][3]);
            }
            else if(a[i][2]>a[i][1] && a[i][2]>=a[i][3])
            {
                favor[i]=2;
                loss[i]=a[i][2]-max(a[i][1],a[i][3]);
            }
            else if(a[i][3]>a[i][1] && a[i][3]>a[i][2])
            {
                favor[i]=3;
                loss[i]=a[i][3]-max(a[i][1],a[i][2]);
            }
            b[favor[i]]++;
            ans+=a[i][favor[i]];
        }
        if(max(max(b[1],b[2]),b[3])>n/2)
        {
            int crowd=1;
            if(b[1]>n/2)
                crowd=1;
            else if(b[2]>n/2)
                crowd=2;
            else if(b[3]>n/2)
                crowd=3;
            for(int i=1;i<=n;i++)
                if(favor[i]==crowd)
                    losss[++lossss]=loss[i];
            sort(losss+1,losss+lossss+1);
            for(int i=1;i<=b[crowd]-n/2;i++)
                ans-=losss[i];
        }
        cout << ans << endl;
    }
    return 0;
}
