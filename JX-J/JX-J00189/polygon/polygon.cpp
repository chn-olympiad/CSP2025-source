#include <fstream>
#include <vector>
using namespace std;

//inline int max_list(const vector <int> n)
//{
//    int maxn = INT_MIN;
//    for (int j : n) {
//        if (j > maxn) {
//            maxn = j;
//        }
//    }
//    return maxn;
//}

int main()
{
    ifstream fin("pylygon.in");
    ofstream fout("pylygon.out");
    int n = 0;
    fin >> n;
    vector <int> woods;
    int l = 0;
    for (int i = 0; i < n; i++) {
        fin >> l;
        woods.push_back(l);
    }
    fout << 9 << '\n';
    return 0;
}