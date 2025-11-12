#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){	
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, score;
    cin >> n >> m;
    v.resize(n*m);
    for(int i=0; i<n*m; i++) cin >> v[i];
    score=v[0];
    // cout << score << endl;
    sort(v.begin(), v.end(), greater<int>());
    // for(int a:v) cout << a << ' ';
    // cout << endl;
    int p=(lower_bound(v.begin(), v.end(), score, greater<int>())-v.begin())+1;
    // cout << p << endl;
    int x=p, y=1;
    m*=2;
    // cout << m << endl << p/m << endl << endl;
    x-=m*(p/m);
    y+=2*(p/m);
    if(x>m/2){x=m-x+1; y+=1;}
    cout << y << ' ' << x;    
    return 0;
}
