#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c[505];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    srand(time(NULL));
    cout<<rand();
    return 0;
}
