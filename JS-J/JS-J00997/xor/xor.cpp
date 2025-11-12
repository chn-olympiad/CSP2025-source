#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n>>k;
    vector<int> a(n+1);
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    int ans = 0,len = a.size();
    for(int j = 1;j<=len;j++)
    {
        if(len == 0)
        {
            break;
        }
        int x = 0;
        for(int i = 1;i<=len;i++)
        {
            x^=a[i];
            if(x == k){
                ans++;
                a.erase(a.begin()+1,a.begin()+i+1);
                len -= i;
                break;
            }
        }
    }
    cout << ans << endl;
}
