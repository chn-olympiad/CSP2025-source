#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    vector<int>grade(n*m);
    for(int i=0;i<n*m;i++)
    {
        cin >> grade[i];
    }
    ll lr=grade[0];
    ll s=0;
    sort(grade.begin(),grade.end());
    for(int i=n*m-1;i>=0;i--)
    {
        if(grade[i]==lr)
        {
            cout << s/n+1 <<" ";
            if((s/n+1)%2==1)
            {
                cout << (s%n+m+1)%(m+1)+1;
            }
            else
            {
                cout << (m+1)-((s%n+m+1)%(m+1)+1);
            }
            return 0;
        }
        s++;
    }
    return 0;
}
