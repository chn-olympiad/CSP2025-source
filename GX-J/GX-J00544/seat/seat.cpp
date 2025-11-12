#include <bits/stdc++.h>
using namespace std;

int seats[200][200];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stout);

    int n, m;
    cin >> n >> m;
    int all = n*m;
    vector<int> scores(all+1);
    for(int i = 1; i <= all; i++)
        cin >> scores[i];
    int target = scores[1];
    sort(scores.begin() + 1, scores.end(), greater<int>());

    int x = 1, y = 1;
    for(int i = 1; i <= all; i++)
    {
        seats[x][y] = scores[i];
        if(seats[x][y] == target)
        {
            cout << y << ' ' << x;
            return 0;
        }
        if(y % 2 != 0)
        {
            if(x+1 <= n)
                x++;
            else if(y+1 <= m)
                y++;
        }
        else
        {
            if(x-1 >= 1)
                x--;
            else if(y+1 <= m)
                y++;
        }
    }

    return 0;
}
