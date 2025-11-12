#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
string a[N], b[N];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    while (q--) {
        string x, y;
        cin >> x >> y;
        int len2 = x.length(), ans = 0;
        for (int i = 1; i <= n; i++) {
            string temp = x;
            int len1 = a[i].length();
            for (int j = 0; j < len2; j++)
                if (temp.substr(j, len1) == a[i]) {
                    for (int k = j; k <= j + len1 - 1; k++)
						temp[k] = b[i][k - j];
					if (temp == y)
						++ans;
					else
						break;
				}
        }
        printf("%d\n", ans);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
