#include <iostream>;
#include <vector>;
#include <algorithm>;
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main(int argc, char const *argv[])
{
    freopen("seat1.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n = 1, m = 1;
    cin >> n >> m;
    vector<int> v(100, 0);
    for (int i = 0; i < n * m; i++)
    {
        cin >> v.at(i);
    }
    int R = v.at(0);
    sort(v.begin(), v.end(), compare);
    //int number = *find(v.begin(), v.end(), R) + 1;
    int number = 1;
    for (int i = 0; i < n * m; i++)
    {
        if(v.at(i) == R)
        {
            number = i + 1;
            break;
        }
    }
    
    int c = number / n, r = 1;
    
    if (number % n != 0)
    {
        c++;
        if (c % 2 == 1)
        {
            r = number % n;
        }
        else
        {
            r = n + 1 - number % n;
        }
    }
    else
    {
        if (c % 2 == 1)
        {
            r = n;
        }
        else
        {
            r = 1;
        }
    }
    cout << c << r << endl;
    return 0;
}
