#include <bits/stdc++.h>
using namespace std;
string rfrom[200000];
string rto[200000];
int n,q;
int h[200000];
void find_sol(string target, string pattern) {

}

int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.sync_with_stdio(false);
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) {
        cin >> rfrom[i] >> rto[i];
    }
    for (int i=0;i<q;i++) {
        printf("%d\n",h[i]);
    }
    return 0;
}