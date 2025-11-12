#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("xor.in");
    ofstream fout("xor.out");
    int cnt = 0;
    int n = 0, k = 0;
    int number = 0;
    fin >> n >> k;
    vector <int> numbers;
    for (int i = 0; i < n; i++) {
        fin >> number;
        if (number == k) {
            cnt++;
            numbers.push_back(-1000);
        } else {
            numbers.push_back(number);
        }
    }

    long long xor_sum = 0;
    const int l = numbers.size();
    int left = 0, right = 0;
    for (; left < l; left++) {
        xor_sum = 0;
        if (numbers[left] < 0) {
            continue;
        }
        xor_sum ^= numbers[left];
        for (right=left+1; right < l; right++) {
            if (numbers[right] < 0) {
                break;
            }
            xor_sum ^= numbers[right];
            if (xor_sum == k) {
                cnt++;
                for (int i = left; i <= right; i++) {
                    numbers[i] = -1000;
                }
                break;
            }
        }
    }

    fout << cnt << '\n';

    return 0;
}