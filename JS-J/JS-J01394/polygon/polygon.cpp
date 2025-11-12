#include <iostream>
#include <vector>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    vector<int>a(n+1);
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    int cnt = rand();
    cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
