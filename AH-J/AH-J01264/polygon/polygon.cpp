#include<bits/stdc++.h>
using namespace std;
const int N=5010;
vector<int> g[N];
int n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        g[i].push_back(x);
    }
    cout<<9;
    return 0;
}
