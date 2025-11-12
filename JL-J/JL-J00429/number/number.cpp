#include <bits/stdc++.h>
using namespace std;
long long a[1000005]={},k=0;
string n;
int main () {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (long long i=0;i<n.size();i++)
        if (n[i]>='0' && n[i]<='9')
            a[++k]=n[i]-'0';
    sort(a+1,a+k+1);
    for (long long i=k;i>=1;i--) cout << a[i];
    return 0;
}
