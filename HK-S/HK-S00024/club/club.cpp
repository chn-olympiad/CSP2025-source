#include <bits/stdc++.h>

using namespace std;

struct TeamScore {
    int a, b, c;

    int first() {
        return max(a, max(b, c));
    }

    int first_idx() {
        if (a >= b && a >= c) {
            return 0;
        }
        if (b >= a && b >= c) {
            return 1;
        }
        if (c >= a && c >= b) {
            return 2;
        }
        return 0;
    }

    int sec_idx() {
        if ((b >= a && b <= c) || (b >= c && b <= a)) {
            return 1;
        }
        if ((c >= b && c <= a) || (c >= a && c <= b)) {
            return 2;
        }
        if ((a >= c && a <= b) || (a >= b && a <= c)) {
            return 0;
        }
        return 0;
    }

    int sec() {
        if (sec_idx() == 0) return a;
        if (sec_idx() == 1) return b;
        if (sec_idx() == 2) return c;
        return 0;
    }

    int cost() {
        return first() - sec();
    }
};

struct abc {
    int a, b, c;

    int first() {
        return max(a, max(b, c));
    }

    int first_idx() {
        if (a >= b && a >= c) {
            return 0;
        }
        if (b >= a && b >= c) {
            return 1;
        }
        if (c >= a && c >= b) {
            return 2;
        }
        return 0;
    }

    int sec_idx() {
        if ((b >= a && b <= c) || (b >= c && b <= a)) {
            return 1;
        }
        if ((c >= b && c <= a) || (c >= a && c <= b)) {
            return 2;
        }
        if ((a >= c && a <= b) || (a >= b && a <= c)) {
            return 0;
        }
        return 0;
    }

    int sec() {
        if (sec_idx() == 0) return a;
        if (sec_idx() == 1) return b;
        if (sec_idx() == 2) return c;
        return 0;
    }

    int cost() {
        return first() - sec();
    }
};

int t, n;


int small_n() {
vector<TeamScore> scores;
    for (int i = 0; i < n; i++) {
        struct TeamScore sc;
        cin >> sc.a >> sc.b >> sc.c;
        scores.push_back(sc);
        // sort(data.begin(), data.end());
        // data[0] = data[2] - data[1];
        // scores.push_back(data);
    }

    int max_score = 0;
    int count = 1 << n;
    // cout << "count: " << count << endl;
    for (int i = 0; i < count; i++) {
        int cnt[3] = {0, 0, 0};
        int scs = 0;
        for (int j = 0; j < n; j++) {
            int parity = (i >> j) % 2;
            int the_score;
            int the_score_idx;
            if (parity == 0) {
                the_score = scores[j].first();
                the_score_idx = scores[j].first_idx();
            } else {
                the_score = scores[j].sec();
                the_score_idx = scores[j].sec_idx();
            }
            // cout << "+=" << the_score << "," << endl;
            cnt[the_score_idx]++;
            if (cnt[the_score_idx] > n/2) {
                // cout << "max" << endl;
                scs = 0;
                break;
            }
            scs += the_score;
        }
         int the_max = scs;
            // cout << "i=" << i << ", The max = " << the_max << endl;
            max_score = max(max_score, the_max);
    }

    return max_score;

}

int large_n() {
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int trash;
        int temp;
        cin >> temp >> trash >> trash;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int sum = 0;
    for (int i = n-1; i >= n/2; i--) {
        sum += arr[i];
    }

    return sum;
}

struct ab {
    int a;
    int b;
    int cost() {
        return abs(a-b);
    }
    int big() {
        return max(a, b);
    }
    int idx() {
        if (a >= b) {
            return 0;
        } else {
            return 1;
        }
    }
};

bool ab_smaller(ab first, ab second) {
    return first.cost() < second.cost(); 
}

bool abc_smaller(abc first, abc second) {
    return first.cost() < second.cost(); 
}

int n_two() {
    vector<ab> a_arr;
    vector<ab> b_arr;
    int a_cnt = 0;
    int b_cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        struct ab datum;
        int trash;
        cin >> datum.a >> datum.b >> trash;
        if (datum.idx() == 0) {
            a_cnt++;
            sum += datum.big();
            a_arr.push_back(datum);
        } else {
            b_cnt++;
            sum += datum.big();
            b_arr.push_back(datum);
        }
    }
        // cout << "a_cnt: " << a_cnt << ", b_cnt: " << b_cnt << endl;
        if (a_cnt == b_cnt) {
            return sum;
        }
        int cnt_diff = abs(a_cnt - b_cnt);
        // cout << "cnt_diff: " << cnt_diff << endl;
        int decrease = 0;
        // Low Cost
        if (a_cnt > b_cnt) {
            sort(a_arr.begin(), a_arr.end(), ab_smaller);
            for (int i = 0; i < cnt_diff/2; i++) {
                decrease += a_arr[i].cost();
            }

        } else {
            sort(b_arr.begin(), b_arr.end(), ab_smaller);
            for (int i = 0; i < cnt_diff/2; i++) {
                decrease += b_arr[i].cost();
            }

        }
            sum -= decrease;

        return sum;
        // for (int i = 0; i < a_arr.size(); i++) {
        //     cout << a_arr[i].cost() << endl;
        // }

    

}

int n_final() {
    vector<abc> a_arr;
    vector<abc> b_arr;
    vector<abc> c_arr;
    int a_cnt = 0;
    int b_cnt = 0;
    int c_cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        struct abc datum;
        int trash;
        cin >> datum.a >> datum.b >> datum.c;
        if (datum.first_idx() == 0) {
            a_cnt++;
            a_arr.push_back(datum);
        } else if (datum.first_idx() == 1) {
            b_cnt++;
            b_arr.push_back(datum);
        } else {
            c_cnt++;
            c_arr.push_back(datum);
        }
            sum += datum.first();
    }
        int max_cnt = max(a_cnt, max(b_cnt, c_cnt));
        // cout << "a_cnt: " << a_cnt << ", b_cnt: " << b_cnt << endl;
        if (max_cnt <= n/2) {
            return sum;
        }
        int cnt_diff = max_cnt - n/2;
        // cout << "cnt_diff: " << cnt_diff << endl;
        int decrease = 0;
        // Low Cost
        if (max_cnt == a_cnt) {
            sort(a_arr.begin(), a_arr.end(), abc_smaller);
            for (int i = 0; i < cnt_diff; i++) {
                decrease += a_arr[i].cost();
            }

        } else if (max_cnt == b_cnt) {
            sort(b_arr.begin(), b_arr.end(), abc_smaller);
            for (int i = 0; i < cnt_diff; i++) {
                decrease += b_arr[i].cost();
            }

        } else {
            sort(c_arr.begin(), c_arr.end(), abc_smaller);
            for (int i = 0; i < cnt_diff; i++) {
                decrease += c_arr[i].cost();
            }

        }
            sum -= decrease;

        return sum;
        // for (int i = 0; i < a_arr.size(); i++) {
        //     cout << a_arr[i].cost() << endl;
        // }

    

}

int trial() {
    cin >> n;
    return n_final();
    // if (n < 100) {
    //     // cout << "small n.." << endl;
    //     return small_n();
    // } else {
    //     return n_final();
    // }
    // } else if (n == 200) {
    //     // cout << "200 n.." << endl;
    //     return n_two();
    // } else
    //  {
    //     // cout << "large n.." << endl;
    //     return large_n();
    // }
    return 0;
}
int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << trial() << endl;
    }
    return 0;
}