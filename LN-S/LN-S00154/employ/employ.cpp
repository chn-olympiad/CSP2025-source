#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct A
{
    int c;
    int i;
} a[510];
int f[510];
bool cmp(A x, A y)
{
    return x.i < y.i;
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out","w", stdout);
    int n, m;
    cin >> n >> m;
    string d;
    cin >> d;
    for(int i = 1; i <= n; i ++)
    {
        a[i].i = i;
        cin >> a[i].c;
    }
    //f[0] = 0;
    int ans = 0;
    do
    {
        memset(f, 0, sizeof(f));
        int sum = 0;
        for(int i = 1; i <= n; i ++)
        {
            if(f[i - 1] >= a[i].c)
            {
                f[i] = f[i - 1] + 1;
                continue;
            }
            if(d[i - 1] == '1')
            {
                sum ++;
                f[i] = f[i - 1];
            }
            else
            {
                f[i] = f[i - 1] + 1;
            }
        }
        if(sum == m)
        {
            ans ++;
            /*for(int i = 1; i <= n; i ++)
                cout << a[i].i << ' ';
            cout << endl;*/
        }
    }
    while(next_permutation(a + 1, a + 1 + n, cmp));
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
