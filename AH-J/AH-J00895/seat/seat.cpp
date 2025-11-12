#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1;
    cin >> n >> m;
    vector<int> v(n*m);
    for(int i=0;i<n*m;i++)
    {
        cin  >> v[i];
    }
    a1=v[0];
    sort(v.begin(),v.end(),cmp);
    int x=1,y=1;
    for(int i=0;i<n*m;i++)
    {
        if(v[i]==a1)
        {
            cout << y << " " << x;
            return 0;
        }
        if(y%2==0)x--;
        else x++;
        if(x<1)
        {
            y++;
            x++;
        }
        if(x>n)
        {
            x--;
            y++;
        }
        cout << y << " " << x << endl;
    }
    return 0;
}
