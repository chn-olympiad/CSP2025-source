#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("club3.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,cnt;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int n;
        cnt = 0;
        cin >> n;
        for(int j = 1;j <= n;j++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            cnt += max(max(a,b),c);
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
