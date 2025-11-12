#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b) {
    return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    int res;
    cin >> n >> m;
    int a[105];
    memset(a,0,sizeof(a));
    for (int i=1;i<=n*m;i++) {
        cin >> a[i];
    }
    int target = a[1];
    sort(a+1,a+101,cmp);
    for (int i=1;i<=n*m;i++) {
        if (a[i] == target) {
            res = i;
            break;
        }
    }
    int c,r;
    if (res<=n) {
        c = 1;
        r = res;
    } else {
            int k = res % n;
    int s = (res-k)/n;
    s = s+1;
    c = s;
    if (s%2==1) {
        r = k;
    } else {
        r = n-k;
    }
    }
    cout << c <<' '<< r << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
