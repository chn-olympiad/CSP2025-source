#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
int diff[505];
int life[505];
string raw_diff;

long long frac(n){
    if (n == 1) return 1;
    return frac(n-1)*n;
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    //Input
    cin>>n>>m;
    cin>>raw_diff;
    for (int i=0;i<n;i++){
        diff[i] = int(raw_diff[i]-'0');
    }
    for (int i=0;i<n;i++) cin>>life[i];
    sort(life,life+n);
    //Solve
    if (m == n) cout<<0;
    else if(m == 1) cout<<frac(n);

    return 0;

}
