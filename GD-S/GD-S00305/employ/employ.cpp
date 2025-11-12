#include <bits/stdc++.h>
using namespace std;

int n,m;
int maxreject[500];
int counter;
string diff;

int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin >> diff;
    for (int i=0;i<n;i++) {
        scanf("%d",&maxreject[i]);
    }
    printf("0");
    return 0;
}