#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;
struct seat{int scr , id;};
seat p[N + 5];
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= n * m ; ++i)
        p[i].id = i , cin >> p[i].scr;
    sort(p + 1 , p + 1 + n * m , [](seat a , seat b){return a.scr > b.scr;});
    int pm = 0;
    for (int i = 1 ; i <= n * m ; ++i)
    {
        if (p[i].id == 1)
        {
            pm = i;
            break;
        }
    }
    int y = (pm - 1) / n + 1;
    if (y & 1)
    {
        int x;
        if (pm % n == 0) x = n;
        else x = pm % n;
        cout << y  << ' ' << x << endl;
    }
    else
    {
        int x;
        if (pm % n == 0) x = 1;
        else x = n - (pm % n) + 1;
        cout << y << ' ' << x << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
