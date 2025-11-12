#include <iostream>

using namespace std;

int N,M,Rscore,ind = 1;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> N >> M;

    for (int i = 1; i <= N * M; ++i)
    {
        int score;
        cin >> score;

        if (i == 1)
        {
            Rscore = score;
        }
        else
        {
            if (score > Rscore) {
                ++ind;
            }
        }
    }

    int i = 1;
    int format = 0;
    while (ind > M)
    {
        format = (format == 1 ? 0 : 1);
        ind -= M;
        i++;
    }

    cout << i << " " << (format == 0 ? ind : M - ind + 1);
    return 0;
}
