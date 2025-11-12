// T_T
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int n;
int sticks[5000];
unsigned long long polygon_count = 0;

vector<vector<int> > result;

int find_max(const vector<int>& array) {
    int maxd = 0;

    for (const int& el : array)
        if (el > maxd)
            maxd = el;

    return maxd;
}

bool is_same_vector(const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;

    return true;
}

bool is_in_result(const vector<int>& target) {
    if (result.size() == 0)
        return false;

    for (auto& vec : result)
        if (is_same_vector(vec, target))
            return true;
    
    return false;
}

bool is_polygon(const vector<int>& choice_sticks) {
    int length = accumulate(choice_sticks.begin(), choice_sticks.end(), 0);
    return length > 2 * find_max(choice_sticks);
}

bool no_same_pos(const int pos_arr[], const int& size, const int& base) {
    for (int i = 0; i < size; i++) {
        if (pos_arr[i] == base)
            return false;
    }

    return true;
}

void update_pos(int pos_arr[], const int& size) {
    pos_arr[0] = pos_arr[0] == n - 1 ? 0 : pos_arr[0] + 1;

    for (int i = 1; i < size; i++)
        pos_arr[i] = pos_arr[i] == n - 1 ? 0 : pos_arr[i - 1] + 1;
}

void handle_elements(int i, int pos_arr[], int j, int length) {
    vector<int> choices = {sticks[i]};
    
    for (int j = 0; j < length; j++)
        choices.push_back(sticks[pos_arr[j]]);

    choices.push_back(sticks[j]);

    sort(choices.begin(), choices.end());

    if (is_polygon(choices) && !is_in_result(choices)) {
        result.push_back(choices);
        polygon_count++;
    }
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> sticks[i];

    for (int state = 3; state <= n; state++) {
        int length = state - 2;
        int pos[length] = {0};

        for (int i = 0; i < n; i++) {
            update_pos(pos, length);

            for (int j = 0; j < n; j++) {
                if (j != i && no_same_pos(pos, length, j))
                    handle_elements(i, pos, j, length);
            }
        }
    }

    cout << (polygon_count + 2) % 998,244,353;
    fclose(stdin);
    fclose(stdout);

    return 0;
}