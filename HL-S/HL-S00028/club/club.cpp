#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a[100001][3];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = 0;
        vector<priority_queue<int, vector<int>, greater<int> > > pq(3);
        vector<int> clubs(3);
        for (int i = 0; i < n; i++) {
            int maxi, maxn = 0, max2i, max2n = 0;
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
                if (a[i][j] >= maxn) {
                	if (maxn >= max2n) {
                		max2n = maxn;
                		max2i = maxi;
					}
                    maxn = a[i][j];
                    maxi = j;
                } else if (a[i][j] >= max2n) {
                	max2i = j;
                	max2n = a[i][j];
				}
            }
            sum += maxn;
            clubs[maxi]++;
            pq[maxi].push(maxn - max2n);
        }
        for (int i = 0; i < 3; i++) {
        	while (pq[i].size() > n / 2) {
        		sum -= pq[i].top();
        		pq[i].pop();
			}
		}
        cout << sum << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
