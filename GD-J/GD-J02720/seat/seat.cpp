#include<bits/stdc++.h>
using namespace std;
struct p{
    int s,i;
};
bool sot(p a,p b){
    return a.s > b.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<p> a;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            int sc;
            cin >> sc;
            a.push_back({sc,i*m+j+1});
        }
    }
    sort(a.begin(),a.end(),sot);
    for (int i = 0;i < n*m;i++)
    {
        if(a[i].i == 1){
            int c = i/n+1,r = (c%2 == 0?n-i%n:i%n+1);
            cout << c <<' ' << r;
        }
    }
    return 0;
}
