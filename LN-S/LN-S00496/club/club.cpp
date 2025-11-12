#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t , n;
int value[N];

int main()
{

    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);

    cin >> t;

    while(t--)
    {

        long long sum = 0;

        cin >> n;

        int x , y;
        for(int i = 1; i <= n; i++)
        {
            cin >> value[i] >> x >> y;
        }



        sort(value + 1 , value + n + 1 , greater<int>());

        for(int i = 1; i <= n / 2; i++)
        {
            sum += value[i];
        }

        cout << sum << endl;
    }






    return 0;


}

//ccfwcnm
