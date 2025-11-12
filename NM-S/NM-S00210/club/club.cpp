#include<bits/stdc++.h>
using namespace std;
int T,n;
struct Node{
    int v,site;
} a[100005],b[100005],c[100005];
int k[5];
bool cmp(Node x,Node y){
    return x.v >= y.v;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>T;
    while(T--){
        bool flag = true;
        cin >> n;
        if (n == 2)
        {
            int ans = 0;
            int a1,a2,a3,b1,b2,b3;
            cin >>a1 >> a2 >> a3 >> b1 >> b2 >> b3;
            if (a1 == max(a1,max(a2,a3)) && b1 == max(b1,max(b2,b3)))
            {
                if (a1 > b1)
                    ans = a1 + max(b2,b3);
                else
                    ans = b1 + max(a2,a3);
                cout << ans <<endl;
                continue;
            }
            else if (a2 == max(a1,max(a2,a3)) && b2 == max(b1,max(b2,b3))){
                if (a2 > b2)
                    ans = a2 + max(b1,b3);
                else
                    ans = b2 + max(a1,a3);
                cout << ans <<endl;
                continue;
            }
            else if (a3 == max(a1,max(a2,a3)) && b3 == max(b1,max(b2,b3))){
                if (a3 > b3)
                    ans = a3 + max(b2,b1);
                else
                    ans = b3 + max(a1,a2);
                cout << ans <<endl;
                continue;
            }
            else{
                cout << max(a1,max(a2,a3)) + max(b1,max(b2,b3)) <<endl;
                continue;
            }
        }
        for (int i = 1;i <= n;i++)
        {
            cin >>a[i].v >> b[i].v >> c[i].v;
            if (b[i].v != 0 && c[i].v != 0)
                flag = false;

        }
        if (flag)
        {
            sort(a + 1,a + n + 1,cmp);
            long long ans = 0;
            for (int i = 1;i <= n/2;i++)
                ans += a[i].v;
            cout <<ans <<endl;
            continue;
        }
        long long ans = 0;
        for (int i = 1;i <= n;i++)
        {
            ans += max(max(a[i].v,b[i].v),c[i].v);
        }
        cout << ans <<endl;
    }
    return 0;
}
