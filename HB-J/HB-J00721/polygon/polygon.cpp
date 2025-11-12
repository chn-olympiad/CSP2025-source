#include <bits/stdc++.h>
using namespace std;
int book[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>book[i];
    }
    sort(book,book+n+1);
    int cnt=0;
    if(book[n-2]+book[n-1]>book[n])
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
