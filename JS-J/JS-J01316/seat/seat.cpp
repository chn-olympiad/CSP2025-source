#include<bits/stdc++.h>
using namespace std;
#define pq priority_queue<int,vector<int>,greater<int> >
#define ll long long
#define endl "\n"
int a[105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i ++)
    {
        cin >> a[i];
    }
    int need = a[1];
    sort(a+1,a+n*m+1,greater<int>());
    //for(int i = 1;i <= n*m;i ++) cout << a[i] << ' ';
    //cout << endl;
    for(int i = 1;i <= n*m;i ++)
    {
        //cout << i << endl;
        if(a[i] == need)
        {
            int r = (i%n?i%n:n),c =i/n + bool(i%n) ;
            if(c%2)
            {
                cout << c <<' ' << r << endl;
            }
            else
            {
                cout << c << ' ' << n-r+1 << endl;
            }
        }
    }
}
