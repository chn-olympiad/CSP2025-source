#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	string s;
	cin >> s;
	int count[10] = {0};
    
    for (int i = 0; i < s.size(); i++) {
        int temp = s[i] - '0';
        if (temp >= 0 && temp <= 9) {
            count[temp]++;
        }
    }

    for (int i = 9; i >= 0; i--) {
        int time = count[i];
        if (time != 0) {
            for (int j = 1; j <= time; j++) {
                cout << i;
            }
        }
    }
    cout << '\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
