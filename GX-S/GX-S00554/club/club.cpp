#include <bits/stdc++.h>
using namespace std;

int n, maxn;
vector<vector<int>> a(15, vector<int>(15));
int earr[4] = {0, 0, 0, 0};

int find(int now, int ans, int lastans, int arr[], int larr[], bool isFirst) {
    if (now == n+1) {
        return ans;
    }
    for (int i=1; i<=3; i++) {
        if (isFirst) {
            for (int j=0; j<4; j++) {
                arr[j] = 0;
                larr[j] = 0;
            }ans = 0;
        }
        if (arr[i] < maxn) {
            lastans = ans;
            ans += a[now][i];
            larr = arr;
            arr[i] += 1;
            ans = max(ans, find(now+1, ans, lastans, arr, larr, false));
        }else {
            if (now - 1 > 1) {
                ans = max(ans, find(now-1, lastans, 0, larr, earr, false));
            }else if (now - 1 == 1) {
                ans = max(ans, find(now-1, lastans, 0, earr, earr, true));
            }else if (now - 1 < 1) break;
        }
    }return ans;
}


int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
    {

        for (int i=0; i<=14; i++) {
            a[i].resize(15, 0);
        }
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        maxn = n/2;
        printf("%d\n", find(1, 0, 0, earr, earr, true));

    }
	fclose(stdin);
	fclose(stdout);
}
