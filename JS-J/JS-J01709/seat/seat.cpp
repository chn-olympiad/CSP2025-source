# include<cstdio>
# include<iostream>
# include<algorithm>
using namespace std;
int n,m,tot,a[105],now = 1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    tot = n*m;
    cin >> a[1];
    for(int i = 2;i<=tot;i++)
    {
        cin >> a[i];
        if(a[i] > a[1])now ++;
    }
    int line = (now-1)/n+1,row;
    if(line % 2 == 1)
    {
        row = (now-1) % n+1;
    }
    else
    {
        row = (n+1-now%n-1)%n+1;
    }
    cout << line << " " << row;
    return 0;
}
