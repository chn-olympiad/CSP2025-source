#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a >= b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);


    // 奇数列从上往下

    int n, m;
    cin >>n >> m;
    vector<int> a(n*m,0);
    for(int i = 0; i<n*m; i++){
        cin >> a[i];
    }

    int R = a[0];

    sort(a.begin(),a.end(),cmp);


    int raw_int = lower_bound(a.begin(),a.end(),R,cmp) - a.begin() - 1;

    int c,r;
    c = raw_int / n +1;
    r = raw_int % m;

    if(c%2){
        r += 1;
    }else{
        r = m - r;
    }

    cout << c << " " << r;

    return 0;
}
