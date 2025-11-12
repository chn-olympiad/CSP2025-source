#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[101],n,m,a1,s;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    a1=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==a1)
        {
            s=i;
            break;
        }
    }
    s=n*m-s+1;
    int lie=ceil(s*1.0/n);
    cout<<lie<<" ";
    if(lie%2==0) cout<<n-(s+n-1)%n;
    else cout<<(s+n-1)%n+1;
    cout<<endl;
    return 0;
}
//luogu914813 Undercraft
//acta est fabula,plaudite
//xi wang bu yao AFO
//shun bian ji lian yong yuan de vivid/stasis
//hao xiang 2026nian jiu ting gen le
//csp-j JS-J00493 csp-s JS-S00500
//chu sai -j 98 -s 72
//di 3 nian le
//ming tian gai si de dong tai shi shi yan zhong xue jiu yao yue kao
//tmd,zhe xiang dang yu cspj-s day 2
//csp-j 2025
//finish at 9:30
//gu ji 100pts
