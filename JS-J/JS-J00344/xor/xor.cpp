#include <iostream>
using namespace std;

long long a[100005];

struct qj
{
    int be,en;
};

qj b[100005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int len = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            int num = a[i];
            for(int q = i + 1;q <= j;q++)
            {
                num = num | a[q];
            }
            if(num == k)
            {
                b[len].be = i,b[len].en = j;
                len++;
            }
        }
    }
    int een = 0;
    int cnt = 0;
    for(int i = 1;i < len;i++)
    {
        if(b[i].be > een)
        {
            cnt++;
            een = b[i].en;
        }
    }
    cout << cnt;
    return 0;
}
