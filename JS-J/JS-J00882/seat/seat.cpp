#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> scores(n*m);
    int rs;

    for(int i=0;i<n*m;i++){
        cin >> scores[i];
    }
    rs = scores.front();
    sort(scores.begin(), scores.end());
    int index = 0;
    for(int i=n*m-1;i>=0;i--){
        index++;
        if(rs == scores[i]){

            break;
        }
    }
    // cout << index << endl;

    if(((index+(n-1))/n)%2 == 0) {// in double row, up
        // cout << "1"<< " " << index%n << endl;
        cout << (index+(n-1))/n << " " << n-(((index%n)==0)?n:(index%n))+1;
    }else{
        // cout << "2" << " " << index%n << endl;
        cout << (index+(n-1))/n << " " << (((index%n)==0)?n:(index%n));
    }

    return 0;
}
