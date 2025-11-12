#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n = 0, m = 0;
    vector <int> marks;
    ifstream fin("seat.in");
    ofstream fout("seat.out");
    fin >> n >> m;

    int number = 0;

    for (int i = 0; i <= n*m; i++) {
        fin >> number;
        marks.push_back(number);
    }

    int mb = marks[0];

    sort(marks.begin(), marks.end(), cmp);

    int index = 1;
    for (int j : marks) {
        if (mb == j) break;
        else index++;
    }


    int x = 0, y = 0;
    x = index/n;
    if (index % n != 0) x++;

    y = index % n;
    if (x % 2 == 1) {
        if (index % n == 0) {
            y = n;
        }
    } else {
        y++;
    }

    fout << x << ' ' << y << '\n';
    return 0;
}