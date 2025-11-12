#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n,m, theR, order;
    cin>>n>>m;
    vector<int> gra(n*m);
    for(int i=0; i<n*m; i++) cin>>gra[i];
    theR = gra[0];
    sort(gra.begin(), gra.end(), greater<>());
    for(int i=0; i<n*m; i++) if(gra[i] == theR){ order = i+1; break; }

    int row = ceil((float)order/n), col = order%n;
    if(col == 0) col = n;
    if(row%2 == 0) col=n-col+1;
    cout<<row<<" "<<col<<"\n";
    return 0;
}   
