#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    int con=n*m;
    int ra,rw;
    for(int i=0;i<con;i++)
    {
        int ci;
        cin>>ci;
        if(i==0){ra=ci;}
        a.push_back(ci);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<con;i++)
    {
        if(a[i]==ra){rw=con-i;}
    }
    int c=(rw-1)/n+1;
    int r;
    if(c%2==1)
    {
        r=rw%n;
        if(r==0){r=n;}
    }
    else
    {
        r=rw%n;
        if(r==0){r=1;}
        else{r=n-r+1;}
    }
    cout<<c<<" "<<r;
    return 0;
}
