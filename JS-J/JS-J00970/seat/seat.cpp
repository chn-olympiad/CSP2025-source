#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int grid = n*m;
    int score[grid+1];
    for(int i = 1;i <= grid;i++)
    {
        cin >> score[i];
    }
    int tgt = score[1],pos = 1;
    sort(score+1,score+grid+1);
    while(score[pos] != tgt)
    {
        pos++;
    }
    int rnk = grid - pos + 1;
    int column = rnk / n;
    int redundant = rnk - n*(rnk/n);
    if(redundant == 0)
    {
        if(column % 2 == 0)
        {
            cout << column << " " << 1 << endl;
        }
        else
        {
            cout << column << " " << n << endl;
        }
    }
    else
    {
        if((column + 1) % 2 == 1)
        {
            cout << column + 1 << " " << redundant << endl;
        }
        else
        {
            cout << column + 1 << " " << n - redundant + 1 << endl;
        }
    }
    return 0;
}
