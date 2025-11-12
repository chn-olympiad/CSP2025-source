#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,a[301000];
int p[1100010],lst = 0,cnt = 0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xpr.out","w",stdout);
    cin >> n >> k;
    for(int i = 1,c;i <= n;i++)
    {
        cin >> c;
        a[i] = c;
        a[i] ^= a[i-1];
        if(!lst && (p[k^a[i]] || (k^a[i]) == 0))
        {
            lst = i;
            cnt++;  
        }
        else if(p[k ^ a[i]] >= lst && p[k^a[i]]) lst = i,cnt++;
        p[a[i]] = i;
    }
    
    cout << cnt;

    return 0;
}
