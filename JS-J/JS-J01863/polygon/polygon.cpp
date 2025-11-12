#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

const unsigned long long modnum = 998244353;

bool mygreater(short a, short b) {return a > b;}

void resetIdx(const std::vector<short> &nums, std::vector<short> &vec, short n, unsigned long long &a)
{
    vec.resize(0, 0);
    vec.resize(n, 0);
    unsigned long long ac = 0;
    for (short i = 0; i < n; ++i)
    {
        vec[i] = i;
        ac += nums[i];
    }
    a = ac;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::vector;
    using std::sort;
    cin.tie(nullptr);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    short n;
    cin >> n;
    vector<short> nums(n);
    vector<short> idxs;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), mygreater);
    unsigned long long combs = 0;
    // brute-force all combinations and read the result
    // guaranteed not to exceed time limit if n <= 20
    for (short sides = 3; sides <= n; ++sides)
    {
        //std::cerr << "Sides advance: " << sides - 1 << " -> " << sides << '\n';
        unsigned long long accumb = 0;    // too lazy to fix typo
        resetIdx(nums, idxs, sides, accumb);
        short workDigit = sides - 1;
        while (true)
        {
            bool adv = false;
            // process current combination if working on last digit
            // the largest side is idxs[0]
            if (workDigit == sides - 1)
            {
                //std::cerr << "Working on combination: ";
                for (short i = 0; i < sides; ++i)
                {
                    //std::cerr << idxs[i] << ' ';
                }
                //std::cerr << '\n';
                if (accumb > 2 * (unsigned long long)nums[idxs[0]])
                {
                    //std::cerr << "Accumulation legit: " << accumb << " > " << nums[idxs[0]] * 2 << '\n';
                    ++combs;
                    combs %= modnum;
                    //std::cerr << "Combination total: " << combs << '\n';
                }
                else
                {
                    //std::cerr << "Accumulation not legit: " << accumb << " <= " << nums[idxs[0]] * 2 << '\n';
                    //std::cerr << "Combination total: " << combs << '\n';
                    // force advance if accumulation is already too small
                    // this works because the accumulation can only be smaller
                    adv = true;
                }
            }
            // proceed to next combination
            if (idxs[workDigit] >= n - sides + workDigit || adv)
            {
                //std::cerr << "Digit too big: " << workDigit << " is " << idxs[workDigit] << \
                            " >= " << n - sides + workDigit << '\n';
                //std::cerr << "Advancing a digit\n";
                if (workDigit == 0) break;
                accumb -= nums[idxs[workDigit]];
                idxs[workDigit] = -1;
                --workDigit;
            }
            else
            {
                accumb -= nums[idxs[workDigit]];
                ++idxs[workDigit];
                accumb += nums[idxs[workDigit]];
                //std::cerr << "Accumulation - " << nums[idxs[workDigit] - 1] << " + " << \
                            nums[idxs[workDigit]] << " = " << accumb << '\n';
                if (workDigit != sides - 1)
                {
                    for (short i = 1; workDigit + i < sides; ++i)
                    {
                        idxs[workDigit + i] = idxs[workDigit] + i;
                        accumb += nums[idxs[workDigit + i]];
                        //std::cerr << "Accumulation += " << nums[idxs[workDigit + i]] << '\n';
                    }
                }
                workDigit = sides - 1;
            }
        }
    }
    cout << combs << '\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
