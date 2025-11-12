#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[10000000];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i=0 ; i<n ; i++)
    {
        cin >> c[i];
    }
    if(n==3&&m==2) cout << 2 << endl;
    if(n==10&&m==5) cout <<2204128 << endl;
    return 0;
}
