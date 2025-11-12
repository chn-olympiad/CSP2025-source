#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18;
int n , m;
int a[100005][5];
vector<int>a1 , a2 , a3;
bool cmp1(int s1 , int s2)
{
    return min(a[s1][1] - a[s1][2] , a[s1][1] - a[s1][3]) > min(a[s2][1] - a[s2][2] , a[s2][1] - a[s2][3]);
}
bool cmp2(int s1 , int s2)
{
    return min(a[s1][2] - a[s1][1] , a[s1][2] - a[s1][3]) > min(a[s2][2] - a[s2][1] , a[s2][2] - a[s2][3]);
}
bool cmp3(int s1 , int s2)
{
    return min(a[s1][3] - a[s1][2] , a[s1][3] - a[s1][1]) > min(a[s2][3] - a[s2][2] , a[s2][3] - a[s2][1]);
}

signed main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    int ___ = 0;
    cin>>___;
    while(___--)
    {
        cin>>n;
        a1.clear() , a2.clear() , a3.clear();
        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])a1.push_back(i) , ans += a[i][1];
            else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])a2.push_back(i) , ans += a[i][2];
            else a3.push_back(i) , ans += a[i][3];
        }
 //       cout<<"check1: "<<ans<<endl;
        if(a1.size() > n / 2)
        {
            sort(a1.begin() , a1.end() , cmp1);
            for(int i = a1.size() - 1 ; i >= n / 2 ; i--)
            {
                int s1 = a1[i];
                ans -= min(a[s1][1] - a[s1][2] , a[s1][1] - a[s1][3]);
            }
        }
        else if(a2.size() > n / 2)
        {
            sort(a2.begin() , a2.end() , cmp2);
            for(int i = a2.size() - 1 ; i >= n / 2 ; i--)
            {
                int s1 = a2[i];
                ans -= min(a[s1][2] - a[s1][1] , a[s1][2] - a[s1][3]);
            }

        }
        else if(a3.size() > n / 2)
        {
            sort(a3.begin() , a3.end() , cmp3);
            for(int i = a3.size() - 1 ; i >= n / 2 ; i--)
            {
                int s1 = a3[i];
                ans -= min(a[s1][3] - a[s1][2] , a[s1][3] - a[s1][1]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
