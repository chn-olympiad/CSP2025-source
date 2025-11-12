#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int g[maxn];
bool cmp(int a,int b)   {
    return a >= b;
}
int main()  {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while (t) {
        int n;
        cin>>n;
        for (int i = 1; i <= n; i++)    {
            int a,b,c;
            cin>>a>>b>>c;
            g[i] = a;
        }
        //for (int i = 1; i <= n; i++)    {
        //    cout<<g[i]<<" ";
        //}
        sort(g + 1,g + n + 1,cmp);
        long long cnt = 0;
        for (int i = 1; i <= n / 2; i++)    {
            cnt += g[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}
