#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n , m ;
    cin  >> n >> m ;
    int s[n*m+2]={};
    int r = 0 ;
    for(int i = 1 ;i <= n*m;i++)
    {

        cin >> s[i];

    }
    r=s[1];
    sort(s+1,s+1+n*m);
    int seat;
    for(int i = 1 ; i <= n*m;i++)
    {
        if(s[i]==r)
        {
            seat=n*m-i+1;
            break;
        }
    }

        int l=(seat-1)/m+1;
        int h=(seat-1)%m+1;
        if(l%2==0)
        {
            h=n-h+1;
        }
         cout << l << " " << h ;
    return 0;
}
