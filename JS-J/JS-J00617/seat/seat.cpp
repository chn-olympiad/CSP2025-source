#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool cmp(int x,int y) { return x>y; }
int n,m,a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++) cin >> a[i];
    int t = a[1];
    sort(a+1,a+n*m+1,cmp);
    int it;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i] == t){
            it = i;
            break;
        }
    }
    int j;
    if(it%n == 0) j = it/n;
    else j = it/n+1;
    int i;
    if(j % 2 == 0) i = n - (it - (j-1)*n) + 1;
    else i = it - (j-1)*n;
    cout << j << ' ' << i;
    return 0;
}
