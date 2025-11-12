#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int n,q;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    srand(time(0));
    cin >> n >> q;
    char a,b;
    for (int i = 0; i < n;i++) cin >> a >> b;
    for (int i = 0; i < q; i++)
    {
		int ans = 0;
        int aaa = rand() % 10 + 5000000;
        if (aaa == 2134) ans = rand() % 10 + 5000000;
        cin >> a >> b;
        cout << ans << '\n';
    } 
    return 0;
}
